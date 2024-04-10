#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <stack>
#include <cassert>
#include <map>
#include <numeric>
#include <cstring>
#include <set>
#include <ctime>
#include <queue>
#include <cmath>
#include <iomanip>
#include <iterator>
#include <unordered_map>

using namespace std;

clock_t timeStart, timeFinish;

void timeBegin() {
    timeStart = clock();
}

void timeEnd() {
    timeFinish = clock();
}

void timeDuration() {
    timeEnd();
    double time_taken = double(timeFinish - timeStart) / double(CLOCKS_PER_SEC);
    cout << "Time taken by program is : " << fixed << time_taken << setprecision(5);
    cout << " sec " << endl;
}

class InputReader {
public:
    InputReader() {
        input_file = stdin;
        cursor = 0;
        fread(buffer, SIZE, 1, input_file);
    }
    InputReader(const char *file_name) {
        input_file = fopen(file_name, "r");
        cursor = 0;
        fread(buffer, SIZE, 1, input_file);
    }
    inline InputReader &operator >>(int &n) {
        while((buffer[cursor] < '0' || buffer[cursor] > '9') && buffer[cursor] != '-') {
            advance();
        }
        int sign = 1;
        if (buffer[cursor] == '-') {
            sign = -1;
            advance();
        }
        n = 0;
        while('0' <= buffer[cursor] && buffer[cursor] <= '9') {
            n = n * 10 + buffer[cursor] - '0';
            advance();
        }
        n *= sign;
        return *this;
    }
private:
    FILE *input_file;
    static const int SIZE = 1 << 17;
    int cursor;
    char buffer[SIZE];
    inline void advance() {
        ++ cursor;
        if(cursor == SIZE) {
            cursor = 0;
            fread(buffer, SIZE, 1, input_file);
        }
    }
};

const int MAXN = 300000;

int a[1 + MAXN];
vector<int> g[1 + MAXN];
int id = 0, where[1 + MAXN];
int start[1 + MAXN], finish[1 + MAXN], degree[1 + MAXN], depth[1 + MAXN];
int dad[1 + MAXN];

bool compare(int x, int y) {
    return a[x] < a[y];
}

void DFS(int node) {
    start[node] = ++id;
    sort(g[node].begin(), g[node].end(), compare);
    for (auto son : g[node]) {
        depth[son] = depth[node] + 1;
        dad[son] = node;
        DFS(son);
    }
    finish[node] = id;
}

int extractMin(priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > &h) {
    int node = h.top().second;
    h.pop();
    if (dad[node] != 0) {
        degree[dad[node]]--;
        if (degree[dad[node]] == 0) {
            h.push({start[dad[node]], dad[node]});
        }
    }
    return node;
}

void reject() {
    cout << "NO\n";
    exit(0);
}

bool isAncestor(int a, int b) {
    return start[a] <= start[b] && finish[b] <= finish[a];
}

bool out[1 + MAXN];

void check(int node) {
    for (auto son : g[node]) {
        if (!out[son]) {
            if (a[son] != id++) {
                reject();
            }
            check(son);
        }
    }
}

int main() {
    timeBegin();
    //ifstream cin("input.in");
    //ofstream cout("output.out");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        where[a[i]] = i;
    }
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
    }
    DFS(1);
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > h;
    for (int i = 1; i <= n; i++) {
        degree[i] = g[i].size();
        if (degree[i] == 0) {
            h.push({start[i], i});
        }
    }
    long long answer = 0;
    for (int i = 1; i <= n; i++) {
        int leaf = extractMin(h);
        if (a[leaf] == i) {
            out[leaf] = true;
            answer += depth[leaf];
        } else if (!isAncestor(where[i], leaf)) {
            reject();
        } else {
            int d = depth[where[i]];
            answer += d;
            int node = dad[where[i]];
            id = i + d + 1;
            check(where[i]);
            out[where[i]] = true;
            while (node != 0) {
                check(node);
                out[node] = true;
                if (a[node] != i + depth[node] + 1) {
                    reject();
                }
                node = dad[node];
            }
            break;
        }
    }
    cout << "YES\n" << answer << "\n";
    for (int i = 1; i <= n; i++) {
        cout << start[i] << " ";
    }
    //timeDuration();
    return 0;
}