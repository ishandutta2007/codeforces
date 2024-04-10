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
const int MOD = 998244353;

int x[1 + MAXN], y[1 + MAXN], s[1 + MAXN];
int dp[1 + MAXN], sum[1 + MAXN];

void add(int &x, int y) {
    x += y;
    if (x >= MOD) {
        x -= MOD;
    }
}

void sub(int &x, int y) {
    x -= y;
    if (x < 0) {
        x += MOD;
    }
}

int binSearch(int c, int n) {
    int left = 1, right = n, ans = n + 1;
    while (left <= right) {
        int middle = (left + right) / 2;
        if (x[middle] > c) {
            ans = middle;
            right = middle - 1;
        } else {
            left = middle + 1;
        }
    }
    return ans;
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
    int ans = 0;
    x[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> x[i] >> y[i] >> s[i];
        add(ans, x[i] - x[i - 1]);
        int j = binSearch(y[i], i - 1);
        dp[i] = x[i] - y[i];
        if (j != i) {
            add(dp[i], sum[i - 1]);
            sub(dp[i], sum[j - 1]);
        }
        sum[i] = sum[i - 1];
        add(sum[i], dp[i]);
        if (s[i] == 1) {
            add(ans, dp[i]);
        }
    }
    add(ans, 1);
    cout << ans << "\n";
    return 0;
}