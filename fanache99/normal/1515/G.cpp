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

const int MAXN = 200000;
const int MAXM = 200000;

vector<pair<int, int > > graph[1 + MAXN];
vector<int> g[1 + MAXN], gt[1 + MAXN];
vector<int> component[1 + MAXN];
bool seen[1 + MAXN];
int which[1 + MAXN];
vector<int> nodes;
long long period[1 + MAXN];

void DFS(int node) {
    seen[node] = true;
    for (auto it : g[node]) {
        if (!seen[it]) {
            DFS(it);
        }
    }
    nodes.push_back(node);
}

void antiDFS(int node, int id) {
    seen[node] = false;
    which[node] = id;
    component[id].push_back(node);
    for (auto it : gt[node]) {
        if (seen[it]) {
            antiDFS(it, id);
        }
    }
}

void kosaraju(int n, int &m) {
    for (int i = 1; i <= n; i++) {
        if (!seen[i]) {
            DFS(i);
        }
    }
    reverse(nodes.begin(), nodes.end());
    for (auto i : nodes) {
        if (seen[i]) {
            antiDFS(i, ++m);
        }
    }
}

long long d[1 + MAXN];

void mark(int node, int id) {
    seen[node] = true;
    for (auto it : graph[node]) {
        if (which[it.first] == id && !seen[it.first]) {
            d[it.first] = d[node] + it.second;
            mark(it.first, id);
        }
    }
}

long long myAbs(long long x) {
    return x < 0 ? -x : x;
}

long long myGcd(long long a, long long b) {
    while (b) {
        long long r = a % b;
        a = b;
        b = r;
    }
    return a;
}

void precompute(int id) {
    mark(component[id].back(), id);
    period[id] = 0;
    for (auto node : component[id]) {
        for (auto it : graph[node]) {
            if (which[it.first] == id) {
                period[id] = myGcd(period[id], d[it.first] - d[node] - it.second);
            }
        }
    }
}

int main() {
    timeBegin();
    //ifstream cin("input.in");
    //ofstream cout("output.out");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    srand(time(0));
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int a, b, l;
        cin >> a >> b >> l;
        graph[a].push_back({b, l});
        g[a].push_back(b);
        gt[b].push_back(a);
    }
    int components = 0;
    kosaraju(n, components);
    for (int i = 1; i <= components; i++) {
        precompute(i);
    }
    int q;
    cin >> q;
    for (int i = 1; i <= q; i++) {
        int node, r, t;
        cin >> node >> r >> t;
        r = (t - r) % t;
        if (r == 0) {
            cout << "YES\n";
        } else {
            int d = myGcd(t, period[which[node]]);
            if (r % d == 0) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }
    return 0;
}