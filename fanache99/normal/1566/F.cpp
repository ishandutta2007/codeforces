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

const int MAXN = 200100;
const int INF = 2000000000;
const long long INFLL = 1e18;

struct Segment {
    int l;
    int r;

    bool operator < (const Segment &other) const {
        if (r != other.r) {
            return r < other.r;
        }
        return l > other.l;
    }
};

Segment s[1 + MAXN], sr[1 + MAXN], sl[1 + MAXN];
int v[1 + MAXN];

void filter(int &m) {
    sort(s + 1, s + m + 1);
    int m0 = 0, last = -INF;
    for (int i = 1; i <= m; i++) {
        if (i != 1 && s[i].r == s[i - 1].r) {
            continue;
        }
        if (s[i].l <= last) {
            continue;
        }
        last = s[i].l;
        m0++;
        s[m0] = s[i];
    }
    m = m0;
}

long long dp[1 + MAXN];
long long pref[1 + MAXN];
long long newDp[1 + MAXN];

void doDp(int x, int ml, int mr) {
    sl[ml + 1] = {x, x};
    sr[0] = {x, x};
    pref[0] = dp[0] - sl[1].r;
    for (int i = 1; i <= ml; i++) {
        pref[i] = min(pref[i - 1], dp[i] - sl[i + 1].r);
    }
    newDp[0] = x + pref[ml];
    long long best = INF;
    for (int i = 1, j = ml; i <= mr; i++) {
        while (j > 0 && x - sl[j].r <= sr[i].l - x) {
            best = min(best, dp[j - 1] - 2 * sl[j].r);
            j--;
        }
        newDp[i] = sr[i].l - x + dp[ml];
        if (j > 0) {
            newDp[i] = min(newDp[i], sr[i].l - x + sr[i].l + pref[j - 1]);
        }
        if (j != ml) {
            newDp[i] = min(newDp[i], sr[i].l + x + best);
        }
    }
}

long long solve(int n, int m) {
    v[n + 1] = INF;
    int p = 1, ml = 0;
    dp[0] = 0;
    while (p <= m && s[p].r < v[1]) {
        ml++;
        sl[ml] = s[p];
        dp[ml] = INFLL;
        p++;
    }
    for (int i = 1; i <= n; i++) {
        while (p <= m && s[p].l <= v[i]) {
            p++;
        }
        int mr = 0;
        while (p <= m && s[p].r < v[i + 1]) {
            mr++;
            sr[mr] = s[p];
            p++;
        }
        doDp(v[i], ml, mr);
        ml = mr;
        for (int j = 0; j <= mr; j++) {
            dp[j] = newDp[j];
            sl[j] = sr[j];
        }
    }
    return dp[ml];
}

int main() {
    timeBegin();
    //ifstream cin("input.in");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    srand(time(0));
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; test++) {
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            cin >> v[i];
        }
        sort(v + 1, v + n + 1);
        for (int i = 1; i <= m; i++) {
            cin >> s[i].l >> s[i].r;
        }
        filter(m);
        cout << solve(n, m) << "\n";
    }
    return 0;
}