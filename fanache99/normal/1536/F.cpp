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

const int MOD = 1000000007;
const int MAXN = 1000000;
const int SMALL = 42069;


int factorial[1 + 2 * MAXN], inverse[1 + 2 * MAXN];

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
    int answer = (1LL * inverse[n - k] * inverse[k]) % MOD;
    answer = (1LL * answer * factorial[n]) % MOD;
    return answer;
}

int same[1 + MAXN], diff[1 + MAXN];
int last[1 + MAXN];

void test() {
    diff[0] = 0;
    int id = 0;
    for (int i = 1; i <= SMALL; i++) {
        // compute for same
        id++;
        for (int j = 1; j <= i; j++) {
            // place same at j
            if (j != 1 && j != i) {
                last[same[j - 1] ^ same[i - j]] = id;
            }

            // place diff at j
            last[diff[j - 1] ^ diff[i - j]] = id;
        }
        same[i] = 0;
        while (last[same[i]] == id) {
            same[i]++;
        }

        // compute for diff
        id++;
        for (int j = 1; j <= i; j++) {
            // place left end
            if (j != 1) {
                last[same[j - 1] ^ diff[i - j]] = id;
            }

            //place right end
            if (j != i) {
                last[diff[j - 1] ^ same[i - j]] = id;
            }
        }
        diff[i] = 0;
        while (last[diff[i]] == id) {
            diff[i]++;
        }

        cout << i << ": " << same[i] << " " << diff[i] << "\n";
    }
}

int main() {
    timeBegin();
    //ifstream cin("input.in");
    //ofstream cout("output.out");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    srand(time(0));
    int n;
    cin >> n;
    precompute(2 * n);
    int answer = 0;
    for (int a = 0; 2 * a <= n; a++) {
        int b = n - 2 * a;
        if ((a + b) % 2 != 0) {
            continue;
        }
        answer = (1LL * combinations(a + b, a) * factorial[a + b - 1] + answer) % MOD;
    }
    answer = (2LL * answer * n) % MOD;
    cout << answer << "\n";
    return 0;
}