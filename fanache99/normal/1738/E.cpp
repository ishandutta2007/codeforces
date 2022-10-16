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
#include <random>

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

const int MAXN = 100000;
const int MOD = 998244353;

int v[1 + MAXN];
int factorial[1 + MAXN], inverse[1 + MAXN], dp[1 + MAXN];

int power(int base, int power) {
    int answer = 1;
    while (power) {
        if (power % 2)
            answer = (1LL * answer * base) % MOD;
        base = (1LL * base * base) % MOD;
        power /= 2;
    }
    return answer;
}

void precompute(int n) {
    factorial[0] = inverse[0] = 1;
    for (int i = 1; i <= n; i++)
        factorial[i] = (1LL * factorial[i - 1] * i) % MOD;
    inverse[n] = power(factorial[n], MOD - 2);
    for (int i = n - 1; i >= 1; i--)
        inverse[i] = (1LL * (i + 1) * inverse[i + 1]) % MOD;
}

int comb(int n, int k) {
    int answer = (1LL * inverse[n - k] * inverse[k]) % MOD;
    answer = (1LL * answer * factorial[n]) % MOD;
    return answer;
}

int mul(int a, int b) {
    return 1LL * a * b % MOD;
}

void add(int &x, int y) {
    x += y;
    if (x >= MOD) {
        x -= MOD;
    }
}

int main() {
    // ifstream cin("input.txt");
//    ofstream cout("output.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    srand(time(0));

    precompute(MAXN);

    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; test++) {
        int n;
        bool allZero = true;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> v[i];
            allZero &= v[i] == 0;
        }
        if (allZero) {
            cout << power(2, n - 1) << "\n";
            continue;
        }
        int ans = 1, l = 0, r = n + 1;
        long long sl = 0, sr = 0;
        while (l < r) {
            if (sl == sr) {
                int zl = 1, zr = 1;
                if (l == 0) {
                    assert(r == n + 1);
                    zl = zr = 0;
                }
                while (l + 1 < r && v[l + 1] == 0) {
                    l++;
                    zl++;
                }
                while (r - 1 > l && v[r - 1] == 0) {
                    r--;
                    zr++;
                }
                if (l + 1 == r) {
                    ans = mul(ans, power(2, zl));
                    break;
                }
                int temp = 0;
                for (int i = 0; i <= min(zl, zr); i++) {
                    add(temp, mul(comb(zl, i), comb(zr, i)));
                }
                ans = mul(ans, temp);
                l++;
                sl += v[l];
                r--;
                sr += v[r];
            } else if (sl < sr) {
                l++;
                sl += v[l];
            } else {
                r--;
                sr += v[r];
            }
        }
        cout << ans << "\n";
    }

    auto stopTime = high_resolution_clock::now();
//    auto duration = duration_cast<milliseconds>(stopTime - startTime);
//    cout << duration.count() << "\n";
    return 0;
}