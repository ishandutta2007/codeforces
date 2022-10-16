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

const int MAXN = 150000;
const int MOD = 998244353;

vector<int> g[1 + MAXN];
int start[1 + MAXN], finish[1 + MAXN], weight[1 + MAXN], id = 0;
bool isBig[1 + MAXN];
int bigSum[1 + MAXN], sum[1 + MAXN], fenwick[1 + MAXN];
vector<int> root[1 + MAXN];

void add(int &x, int y) {
    x += y;
    if (x >= MOD) {
        x -= MOD;
    }
}

int raiseToPower(int base, int power) {
    int answer = 1;
    while (power) {
        if (power & 1) {
            answer = 1LL * answer * base % MOD;
        }
        base = 1LL * base * base % MOD;
        power >>= 1;
    }
    return answer;
}

void DFS(int node, int father) {
    start[node] = ++id;
    weight[node] = 1;
    for (auto son : g[node]) {
        if (son != father) {
            DFS(son, node);
            weight[node] += weight[son];
        }
    }
    finish[node] = id;
}

void fixRoot(int node, int father, int subtree, vector<int> &which) {
    which[node] = subtree;
    for (auto son : g[node]) {
        if (son != father) {
            fixRoot(son, node, subtree, which);
        }
    }
}

void update(int x, int n, int y) {
    for (; x <= n; x += (x & -x)) {
        add(fenwick[x], y);
    }
}

void updateRange(int a, int b, int x, int n) {
    update(a, n, x);
    update(b + 1, n, (MOD - x) % MOD);
}

int query(int x) {
    int answer = 0;
    for (; x > 0; x -= (x & -x)) {
        add(answer, fenwick[x]);
    }
    return answer;
}

int main() {
    timeBegin();
    //ifstream cin("input.in");
    //ofstream cout("output.out");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    srand(time(0));
    int n, q;
    cin >> n >> q;
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    DFS(1, 0);
    vector<int> bigNodes;
    for (int i = 1; i <= n; i++) {
        sum[i] = 0;
        if (g[i].size() > sqrt(n)) {
            isBig[i] = true;
            bigNodes.push_back(i);
            bigSum[i] = 0;
            root[i] = vector<int> (n + 1, 0);
            root[i][i] = n;
            for (auto j : g[i]) {
                int w = (weight[j] < weight[i] ? weight[j] : n - weight[i]);
                fixRoot(j, i, w, root[i]);
            }
        }
    }
    int divn = raiseToPower(n, MOD - 2);
    for (int i = 1; i <= q; i++) {
        int type;
        cin >> type;
        if (type == 1) {
            int node, d;
            cin >> node >> d;
            if (isBig[node]) {
                add(bigSum[node], d);
            } else {
                add(sum[node], d);
                for (auto it : g[node]) {
                    if (weight[it] < weight[node]) {
                        int x = 1LL * d * (n - weight[it]) % MOD * divn % MOD;
                        updateRange(start[it], finish[it], x, n);
                    } else {
                        int x = 1LL * d * weight[node] % MOD * divn % MOD;
                        updateRange(start[1], finish[1], x, n);
                        updateRange(start[node], finish[node], (MOD - x) % MOD, n);
                    }
                }
            }
        } else {
            int node;
            cin >> node;
            int answer = query(start[node]);
            add(answer, sum[node]);
            for (auto big : bigNodes) {
                if (big == node) {
                    add(answer, bigSum[big]);
                } else {
                    add(answer, 1LL * bigSum[big] * (n - root[big][node]) % MOD * divn % MOD);
                }
            }
            cout << answer << "\n";
        }
    }
    return 0;
}