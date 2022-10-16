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

using namespace std;

class InputReader {
public:
    InputReader() {
        input_file = stdin;
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

const int MAXN = 5000;

vector<int> g[1 + MAXN];
vector<vector<int> > side[2];
bool seen[1 + MAXN];
int color[1 + MAXN];
bool bad = false;
bool can[1 + MAXN][1 + MAXN];
int last[1 + MAXN][1 + MAXN];

void DFS(int node, int current) {
    seen[node] = true;
    color[node] = current;
    side[current].back().emplace_back(node);
    for (auto it : g[node])
        if (!seen[it])
            DFS(it, current ^ 1);
        else
            if (color[it] == color[node])
                bad = true;
}

int main() {
    //ifstream cin("input.in");
    int n, m, n1, n2, n3;
    cin >> n >> m >> n1 >> n2 >> n3;
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }
    for (int i = 1; i <= n; i++)
        if (!seen[i]) {
            side[0].emplace_back(vector<int>());
            side[1].emplace_back(vector<int>());
            DFS(i, 1);
        }
    if (bad) {
        cout << "NO\n";
        return 0;
    }
    can[0][0] = true;
    for (int i = 1; i <= side[0].size(); i++) {
        int a = side[0][i - 1].size(), b = side[1][i - 1].size();
        for (int j = 0; j <= n; j++) {
            if (j >= a && can[i - 1][j - a]) {
                can[i][j] = true;
                last[i][j] = 0;
            } else if (j >= b && can[i - 1][j - b]) {
                can[i][j] = true;
                last[i][j] = 1;
            }
        }
    }
    if (!can[side[0].size()][n2]) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    for (int i = side[0].size(), j = n2, k = n1; i >= 1; i--) {
        if (last[i][j] == 1)
            swap(side[0][i - 1], side[1][i - 1]);
        for (auto it : side[0][i - 1])
            color[it] = 2;
        for (auto it : side[1][i - 1])
            if (k > 0) {
                color[it] = 1;
                k--;
            } else
                color[it] = 3;
        j -= side[0][i - 1].size();
    }
    for (int i = 1; i <= n; i++)
        cout << color[i];
    cout << "\n";
    return 0;
}