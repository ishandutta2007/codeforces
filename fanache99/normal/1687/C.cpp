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

const int MAXN = 200000;

int a[1 + MAXN];
long long sum[1 + MAXN];
vector<int> g[1 + MAXN];

int main() {
    // ifstream cin("input.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; test++) {
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        for (int i = 1; i <= n; i++) {
            int b;
            cin >> b;
            a[i] -= b;
            sum[i] = sum[i - 1] + a[i];
        }
        for (int i = 1; i <= m; i++) {
            int l, r;
            cin >> l >> r;
            g[l - 1].push_back(r);
            g[r].push_back(l - 1);
        }
        set<int> notZero;
        queue<int> zero;
        for (int i = 0; i <= n; i++) {
            if (sum[i] == 0) {
                zero.push(i);
            } else {
                notZero.insert(i);
            }
        }
        while (!zero.empty()) {
            int pos = zero.front();
            zero.pop();
            for (auto other : g[pos]) {
                int l = min(pos, other), r = max(pos, other);
                if (sum[l] != sum[r]) {
                    continue;
                }
                auto it = notZero.lower_bound(l);
                while (it != notZero.end() && *it <= r) {
                    zero.push(*it);
                    sum[*it] = 0;
                    notZero.erase(it);
                    it = notZero.lower_bound(l);
                }
            }
        }
        cout << (notZero.empty() ? "YES" : "NO") << "\n";
        for (int i = 0; i <= n; i++) {
            g[i].clear();
        }
    }

    auto stopTime = high_resolution_clock::now();
//    auto duration = duration_cast<milliseconds>(stopTime - startTime);
//    cout << duration.count() << "\n";
    return 0;
}