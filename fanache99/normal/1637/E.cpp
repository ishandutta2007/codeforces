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

const int MAXN = 300000;
const int MAXM = 300000;
const int MOD = 666013;
const int BASE = 1000000007;

vector<int> v[1 + MAXN];
vector<long long> table[MOD];

int x[1 + MAXM], y[1 + MAXM];

long long code(int a, int b) {
    return 1LL * a * BASE + b;
}

void add(int a, int b) {
    if (a > b) {
        swap(a, b);
    }
    long long h = code(a, b);
    table[h % MOD].push_back(h);
}

bool is(int a, int b) {
    if (a > b) {
        swap(a, b);
    }
    long long h = code(a, b);
    int bucket = h % MOD;
    for (auto it : table[bucket]) {
        if (it == h) {
            return true;
        }
    }
    return false;
}

int main() {
    timeBegin();
    // ifstream cin("input.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; test++) {
        int n, m;
        cin >> n >> m;
        map<int, int> cnt;
        for (int i = 1; i <= n; i++) {
            int x;
            cin >> x;
            cnt[x]++;
        }
        for (int i = 1; i <= m; i++) {
            cin >> x[i] >> y[i];
            add(x[i], y[i]);
        }

        vector<int> haveCnt;
        for (auto &it : cnt) {
            v[it.second].push_back(it.first);
            haveCnt.push_back(it.second);
        }
        sort(haveCnt.begin(), haveCnt.end());
        haveCnt.resize(unique(haveCnt.begin(), haveCnt.end()) - haveCnt.begin());
        for (auto f : haveCnt) {
            sort(v[f].begin(), v[f].end());
        }

        long long ans = 0;
        for (auto &it : cnt) {
            auto [v1, f1] = it;
            for (auto f2 : haveCnt) {
                int p = (int) (v[f2].size()) - 1;
                while (p >= 0 && (v[f2][p] == v1 || is(v1, v[f2][p]))) {
                    p--;
                }
                if (p >= 0) {
                    int v2 = v[f2][p];
                    ans = max(ans, 1LL * (f1 + f2) * (v1 + v2));
                }
            }
        }

        cout << ans << "\n";
        for (int i = 1; i <= n; i++) {
            v[i].clear();
        }
        for (int i = 1; i <= m; i++) {
            long long h = code(x[i], y[i]);
            table[h % MOD].clear();
        }
    }
    return 0;
}