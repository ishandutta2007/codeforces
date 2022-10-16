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

const int MAXN = 50;
const int MAXM = 50;
const int MOD = 998244353;

bool likes[1 + MAXN];
int w[1 + MAXN];
int dpGood[1 + MAXM][1 + MAXM], dpBad[1 + MAXM][1 + MAXM];

int mul(int a, int b) {
    return 1LL * a * b % MOD;
}

int pow(int base, int power) {
    int ans = 1;
    while (power) {
        if (power & 1) {
            ans = mul(ans, base);
        }
        base = mul(base, base);
        power >>= 1;
    }
    return ans;
}

int inv(int x) {
    return pow(x, MOD - 2);
}

void add(int &x, int y) {
    x += y;
    if (x >= MOD) {
        x -= MOD;
    }
}

int main() {
    timeBegin();
    // ifstream cin("input.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> likes[i];
    }
    int sumGood = 0, sumBad = 0;
    for (int i = 1; i <= n; i++) {
        cin >> w[i];
        if (likes[i]) sumGood += w[i];
        else sumBad += w[i];
    }
    for (int j = 0; j <= m; j++) {
        int k = m - j;
        dpGood[j][k] = dpBad[j][k] = 1;
    }
    for (int i = m - 1; i >= 0; i--) {
        for (int j = 0; j <= i; j++) {
            int k = i - j;
            int div = inv(sumGood + sumBad + j - k);

            add(dpGood[j][k], mul(dpGood[j + 1][k], mul(sumGood + j + 1, div)));
            add(dpGood[j][k], mul(dpGood[j][k + 1], mul(sumBad - k, div)));

            add(dpBad[j][k], mul(dpBad[j + 1][k], mul(sumGood + j, div)));
            add(dpBad[j][k], mul(dpBad[j][k + 1], mul(sumBad - k - 1, div)));
        }
    }
    for (int i = 1; i <= n; i++) {
        if (likes[i]) cout << mul(w[i], dpGood[0][0]) << "\n";
        else cout << mul(w[i], dpBad[0][0]) << "\n";
    }
    return 0;
}