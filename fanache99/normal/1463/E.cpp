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

class InputReader {
public:
    InputReader() {}
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

int parent[1 + MAXN];
vector<int> g[1 + MAXN];
int after[1 + MAXN], before[1 + MAXN], component[1 + MAXN], level[1 + MAXN];
int beginning[1 + MAXN], q[1 + MAXN], degree[1 + MAXN];

void DFS(int node, int depth, int id) {
    component[node] = id;
    level[node] = depth;
    if (after[node]) {
        DFS(after[node], depth + 1, id);
    }
}

void print(int node) {
    cout << node << " ";
    if (after[node]) {
        print(after[node]);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //ifstream cin("input.txt");
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> parent[i];
    }
    for (int i = 1; i <= k; i++) {
        int x, y;
        cin >> x >> y;
        before[y] = x;
        after[x] = y;
    }
    int m = 0;
    for (int i = 1; i <= n; i++) {
        if (!before[i]) {
            m++;
            beginning[m] = i;
            DFS(i, 1, m);
        }
    }
    for (int i = 1; i <= n; i++) {
        if (parent[i]) {
            int a = component[parent[i]], b = component[i];
            if (a == b) {
                if (level[parent[i]] > level[i]) {
                    cout << "0\n";
                    return 0;
                } else {
                    continue;
                }
            }
            g[a].push_back(b);
            degree[b]++;
        }
    }
    int start = 1, finish = 0;
    for (int i = 1; i <= m; i++) {
        if (!degree[i]) {
            finish++;
            q[finish] = i;
        }
    }
    while (start <= finish) {
        int comp = q[start];
        start++;
        for (auto it : g[comp]) {
            degree[it]--;
            if (!degree[it]) {
                finish++;
                q[finish] = it;
            }
        }
    }
    if (finish != m) {
        cout << "0\n";
        return 0;
    }
    for (int i = 1; i <= m; i++) {
        print(beginning[q[i]]);
    }
    return 0;
}