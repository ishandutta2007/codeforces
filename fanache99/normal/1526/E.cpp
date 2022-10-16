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
#include <unordered_map>
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
const int MOD = 998244353;

int v[1 + MAXN], w[1 + MAXN + 1];
int factorial[1 + MAXN], inverse[1 + MAXN];

int raiseToPower(int base, int power) {
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
    inverse[n] = raiseToPower(factorial[n], MOD - 2);
    for (int i = n - 1; i >= 1; i--)
        inverse[i] = (1LL * (i + 1) * inverse[i + 1]) % MOD;
}

int combinations(int n, int k) {
    if (n < k) {
        return 0;
    }
    int answer = (1LL * inverse[n - k] * inverse[k]) % MOD;
    answer = (1LL * answer * factorial[n]) % MOD;
    return answer;
}

int main() {
    timeBegin();
    //ifstream cin("input.in");
    //ofstream cout("output.out");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    srand(time(0));
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        w[v[i]] = i;
    }
    w[n + 1] = 0;
    int maybe = 0;
    for (int i = 1; i < n; i++) {
        int a = v[i], b = v[i + 1];
        if (w[a + 1] < w[b + 1]) {
            maybe++;
        }
    }
    precompute(max(n, k));
    int answer = 0;
    for (int i = 0; i <= maybe; i++) {
        int x = 1 + (n - 1 - maybe) + i;
        answer = (1LL * combinations(k, x) * combinations(maybe, i) + answer) % MOD;
    }
    cout << answer << "\n";
    return 0;
}