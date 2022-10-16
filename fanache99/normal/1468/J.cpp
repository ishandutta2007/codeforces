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

const int MAXN = 200000;
const int MAXM = 200000;
const long long INF = 1000000000000000000LL;

struct Edge {
    int a, b, c;

    bool operator < (const Edge &other) const {
        return c < other.c;
    }
};

Edge e[1 + MAXN];
vector<pair<int, int> > g[1 + MAXN];
int reached = 0, k;
bool seen[1 + MAXN];

void DFS(int node) {
    reached++;
    seen[node] = true;
    for (auto it : g[node]) {
        if (it.second <= k && !seen[it.first]) {
            DFS(it.first);
        }
    }
}

int abs(int x) {
    return x > 0 ? x : -x;
}

int dad[1 + MAXN], h[1 + MAXN];

int findDad(int node) {
    if (dad[node] == node) {
        return node;
    }
    return dad[node] = findDad(dad[node]);
}

void join(int a, int b) {
    if (h[a] > h[b]) {
        dad[b] = a;
    } else {
        if (h[a] == h[b]) {
            h[b]++;
        }
        dad[a] = b;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //ifstream cin("input.txt");
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; test++) {
        int n, m;
        cin >> n >> m >> k;
        for (int i = 1; i <= m; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            g[a].push_back(make_pair(b, c));
            g[b].push_back(make_pair(a, c));
            e[i] = {a, b, c};
        }
        reached = 0;
        DFS(1);
        if (reached == n) {
            long long answer = INF;
            for (int i = 1; i <= m; i++) {
                answer = min(answer, (long long) abs(k - e[i].c));
            }
            cout << answer << "\n";
        } else {
            for (int i = 1; i <= n; i++) {
                dad[i] = i;
                h[i] = 1;
            }
            sort(e + 1, e + m + 1);
            long long answer = 0;
            for (int i = 1; i <= m; i++) {
                int a = findDad(e[i].a), b = findDad(e[i].b);
                if (a != b) {
                    join(a, b);
                    answer += max(0, e[i].c - k);
                }
            }
            cout << answer << "\n";
        }
        for (int i = 1; i <= n; i++) {
            g[i].clear();
            seen[i] = false;
        }
    }
    return 0;
}