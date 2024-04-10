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
#include <bitset>
#include <unordered_map>
#include <complex>
#include <unordered_set>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

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

    inline InputReader &operator>>(int &n) {
        while ((buffer[cursor] < '0' || buffer[cursor] > '9') && buffer[cursor] != '-') {
            advance();
        }
        int sign = 1;
        if (buffer[cursor] == '-') {
            sign = -1;
            advance();
        }
        n = 0;
        while ('0' <= buffer[cursor] && buffer[cursor] <= '9') {
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
        ++cursor;
        if (cursor == SIZE) {
            cursor = 0;
            fread(buffer, SIZE, 1, input_file);
        }
    }
};

const int MAXNODES = 400000;

int n, m;
int dr[4] = {0, 1, 0, -1};
int dc[4] = {1, 0, -1, 0};
vector<int> g[MAXNODES], gt[MAXNODES];
bool seen[MAXNODES];

bool inside(int r, int c) {
    return (r >= 0 && r < n && c >= 0 && c < m);
}

int code(int r, int c) {
    return r * m + c;
}

void addEdge(int r1, int c1, int r2, int c2) {
    int a = code(r1, c1), b = code(r2, c2);
    g[a].push_back(b);
    gt[b].push_back(a);
}

void addEdges(int r, int c, vector<string> &s, vector<vector<int> > &below) {
    for (int i = 0; i < 4; i++) {
        int r0 = r + dr[i], c0 = c + dc[i];
        if (inside(r0, c0) && s[r0][c0] == '#') {
            addEdge(r, c, r0, c0);
        }
    }
    for (int c0 = c - 1; c0 <= c + 1; c0++) {
        if (c0 >= 0 && c0 < m) {
            int r0 = below[(c0 == c ? r + 1 : r)][c0];
            if (r0 >= 0 && r0 < n && s[r0][c0] == '#') {
                addEdge(r, c, r0, c0);
            }
        }
    }
}

vector<int> nodes;
int comp[MAXNODES], in[MAXNODES];

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
    comp[node] = id;
    for (auto it : gt[node]) {
        if (seen[it]) {
            antiDFS(it, id);
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
    cin >> n >> m;
    vector<string> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    vector<int> v(m);
    vector<vector<int> > below(n + 1, vector<int>(m));
    for (int j = 0; j < m; j++) {
        cin >> v[j];
        below[n][j] = n;
        for (int i = n - 1; i >= 0; i--) {
            below[i][j] = below[i + 1][j];
            if (s[i][j] == '#') {
                below[i][j] = i;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i][j] == '#') {
                addEdges(i, j, s, below);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i][j] == '#' && !seen[code(i, j)]) {
                DFS(code(i, j));
            }
        }
    }
    reverse(nodes.begin(), nodes.end());
    int comps = 0;
    for (auto node : nodes) {
        if (seen[node]) {
            antiDFS(node, comps);
            comps++;
        }
    }
    for (auto i : nodes) {
        for (auto j : g[i]) {
            if (comp[i] != comp[j]) {
                in[comp[j]]++;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < comps; i++) {
        if (in[i] == 0) {
            ans++;
        }
    }
    cout << ans << "\n";
    return 0;
}