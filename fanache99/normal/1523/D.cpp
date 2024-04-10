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
const int MAXM = 60;
const int MAXP = 15;
const int STEPS = 50;

char s[1 + MAXN][MAXM];
long long mask[1 + MAXN];
int v[1 << MAXP], dp[1 << MAXP];

int myRand() {
    return (rand() << 16) + rand();
}

int transform(long long mask1, long long mask2, int m) {
    int mask = 0;
    for (int i = 0, b = 0; i < m; i++) {
        if ((mask1 >> i) & 1) {
            if ((mask2 >> i) & 1) {
                mask |= 1 << b;
            }
            b++;
        }
    }
    return mask;
}

long long retransform(long long mask1, int mask2, int m) {
    long long mask = 0;
    for (int i = 0, b = 0; i < m; i++) {
        if ((mask1 >> i) & 1) {
            if ((mask2 >> b) & 1) {
                mask |= (1LL << i);
            }
            b++;
        }
    }
    return mask;
}

int main() {
    timeBegin();
    //ifstream cin("input.in");
    //ofstream cout("output.out");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    srand(time(0));
    int n, m, p;
    cin >> n >> m >> p;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        for (int j = 0; j < m; j++) {
            if (s[i][j] == '1') {
                mask[i] |= (1LL << j);
            }
        }
    }
    long long answer = 0;
    for (int step = 1; step <= STEPS; step++) {
        int x = myRand() % n + 1;
        int b = __builtin_popcountll(mask[x]);
        if (b == 0) {
            continue;
        }
        assert(b <= p);
        for (int i = 0; i < (1 << b); i++) {
            v[i] = 0;
        }
        for (int i = 1; i <= n; i++) {
            int newMask = transform(mask[x], mask[i], m);
            v[newMask ^ ((1 << b) - 1)]++;
        }
        for (int i = 0; i < (1 << b); i++) {
            dp[i] = v[i];
        }
        for (int i = 0; i < b; i++) {
            for (int j = 0; j < (1 << b); j++) {
                if ((j >> i) & 1) {
                    dp[j] += dp[j ^ (1 << i)];
                }
            }
        }
        for (int i = 0; i < (1 << b); i++) {
            if (dp[i] >= (n + 1) / 2) {
                int mask1 = (i ^ ((1 << b) - 1));
                long long mask2 = retransform(mask[x], mask1, m);
                if (__builtin_popcountll(mask2) > __builtin_popcountll(answer)) {
                    answer = mask2;
                }
            }
        }
    }
    for (int j = 0; j < m; j++) {
        cout << ((answer >> j) & 1);
    }
    return 0;
}