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
    inline InputReader &operator >>(long long &n) {
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
const int MAXLOG = 20;

vector<int> g[1 + MAXN];

int dad[1 + MAXN][1 + MAXLOG];
int depth[1 + MAXN];

void DFS(int node, int father) {
    depth[node] = depth[father] + 1;
    dad[node][0] = father;
    for (int i = 1; (1 << i) < depth[node]; i++) {
        dad[node][i] = dad[dad[node][i - 1]][i - 1];
    }
    for (auto son : g[node]) {
        if (son != father) {
            DFS(son, node);
        }
    }
}

int raise(int node, int delta) {
    for (int i = 0; i <= MAXLOG; i++) {
        if (delta & (1 << i)) {
            node = dad[node][i];
        }
    }
    return node;
}

int lca(int a, int b) {
    if (depth[a] < depth[b]) {
        swap(a, b);
    }
    a = raise(a, depth[a] - depth[b]);
    for (int i = MAXLOG; i >= 0; i--) {
        if (dad[a][i] != dad[b][i]) {
            a = dad[a][i];
            b = dad[b][i];
        }
    }
    if (a != b) {
        a = dad[a][0];
    }
    return a;
}

int nodes[1 + MAXN], edges[1 + MAXN];
vector<pair<int, int> > paths[1 + MAXN];
int seen[1 + MAXN];
long long answer = 0;

void solve(int node, int father) {
    for (auto son : g[node]) {
        if (son != father) {
            solve(son, node);
            nodes[node] += nodes[son];
            edges[node] += edges[son];
        }
    }
    answer += 1LL * (nodes[node] - 1) * paths[node].size();
    sort(paths[node].begin(), paths[node].end());
    int before = 0;
    for (auto it : paths[node]) {
        answer -= before;
        if (it.first != node) {
            answer -= edges[it.first] - 1;
            answer += seen[it.first];
            seen[it.first]++;
        }
        if (it.second != node) {
            answer -= edges[it.second] - 1;
            answer += seen[it.second];
            seen[it.second]++;
        }
        before++;
    }
    for (int i = 0, j; i < paths[node].size(); i = j) {
        j = i;
        while (j < paths[node].size() && paths[node][i] == paths[node][j]) {
            j++;
        }
        if (paths[node][i].first != node && paths[node][i].second != node) {
            answer += 1LL * (j - i - 1) * (j - i) / 2;
        }
    }
}

int main() {
    timeBegin();
    //ifstream cin("input.txt");
    //ofstream cout("greutati.out");
    int n;
    cin >> n;
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    DFS(1, 0);
    int m;
    cin >> m;
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        int c = lca(a, b);
        nodes[a]++;
        nodes[b]++;
        nodes[c]--;
        nodes[dad[c][0]]--;
        edges[a]++;
        edges[b]++;
        edges[c] -= 2;
        if (a != c) {
            a = raise(a, depth[a] - depth[c] - 1);
        }
        if (b != c) {
            b = raise(b, depth[b] - depth[c] - 1);
        }
        if (a > b) {
            swap(a, b);
        }
        paths[c].push_back({a, b});
    }
    solve(1, 0);
    cout << answer << "\n";
    //timeDuration();
    return 0;
}