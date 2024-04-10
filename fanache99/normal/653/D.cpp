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
#include <chrono>
#include <random>
#include <functional>

using namespace std;
using namespace std::chrono;

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

    template<typename T>
    inline InputReader &operator>>(T &n) {
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

const int MAXN = 50;
const int MAXVAL = 1000000;
const int STEPS = 60;
const long long INF = 1e16;

long long capInit[1 + MAXN][1 + MAXN], cap[1 + MAXN][1 + MAXN], flow[1 + MAXN][1 + MAXN];
vector<int> g[1 + MAXN], gt[1 + MAXN];
int dad[1 + MAXN];
bool seen[1 + MAXN];

bool BFS(int n) {
    for (int i = 1; i <= n; i++) {
        seen[i] = false;
    }
    queue<int> q;
    q.push(1);
    seen[1] = true;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        if (node == n) {
            continue;
        }
        for (auto next : g[node]) {
            if (seen[next] || flow[node][next] == cap[node][next]) {
                continue;
            }
            seen[next] = true;
            dad[next] = node;
            q.push(next);
        }
    }
    return seen[n];
}

int maxFlow(int n) {
    long long ans = 0;
    while (BFS(n)) {
        for (auto before : gt[n]) {
            if (flow[before][n] == cap[before][n] || !seen[before]) {
                continue;
            }
            dad[n] = before;
            long long add = INF;
            for (int node = n; node != 1; node = dad[node]) {
                add = min(add, cap[dad[node]][node] - flow[dad[node]][node]);
            }
            if (add == 0) {
                continue;
            }
            for (int node = n; node != 1; node = dad[node]) {
                flow[dad[node]][node] += add;
                flow[node][dad[node]] -= add;
            }
            ans += add;
        }
    }
    return ans;
}

bool check(int n, long long x, double f) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cap[i][j] = capInit[i][j] / f;
            flow[i][j] = 0;
        }
    }
    return maxFlow(n) >= x;
}

int main() {
    // ifstream cin("input.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    long long x;
    cin >> n >> m >> x;
    for (int i = 1; i <= m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back(b);
        gt[b].push_back(a);
        capInit[a][b] = c;
    }
    double left = 0, right = MAXVAL;
    for (int step = 1; step <= STEPS; step++) {
        double middle = (left + right) / 2;
        if (check(n, x, middle)) {
            left = middle;
        } else {
            right = middle;
        }
    }
    cout << fixed << setprecision(10) << left * x << "\n";
    auto stopTime = high_resolution_clock::now();
//    auto duration = duration_cast<milliseconds>(stopTime - startTime);
//    cout << duration.count() << "\n";
    return 0;
}