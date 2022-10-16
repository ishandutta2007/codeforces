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

const int MAXN = 200000;

vector<int> g[1 + MAXN];
int v[1 + MAXN], d[2][1 + MAXN], w[1 + MAXN];

void BFS(int start, int n, int dist[]) {
    for (int i = 1; i <= n; i++) {
        dist[i] = 2 * n;
    }
    queue<int> q;
    q.push(start);
    dist[start] = 0;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (auto it : g[node]) {
            if (dist[it] > dist[node] + 1) {
                dist[it] = dist[node] + 1;
                q.push(it);
            }
        }
    }
}

bool cmp(int a, int b) {
    return d[0][v[a]] - d[1][v[a]] < d[0][v[b]] - d[1][v[b]];
}

int main() {
    timeBegin();
    //ifstream cin("input.in");
    //ofstream cout("output.out");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    srand(time(0));
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= k; i++) {
        cin >> v[i];
        w[i] = i;
    }
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    BFS(1, n, d[0]);
    BFS(n, n, d[1]);
    sort(w + 1, w + k + 1, cmp);
    int best = 0, big = d[0][v[w[1]]];
    for (int i = 2; i <= k; i++) {
        best = max(best, big + d[1][v[w[i]]] + 1);
        big = max(big, d[0][v[w[i]]]);
    }
    cout << min(d[0][n], best);
    return 0;
}