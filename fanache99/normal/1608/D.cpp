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

const int MAXN = 100000;
const int MOD = 998244353;

int factorial[1 + MAXN], inverse[1 + MAXN];

int RaiseToPower(int base, int power) {
    int answer = 1;
    while (power) {
        if (power % 2)
            answer = (1LL * answer * base) % MOD;
        base = (1LL * base * base) % MOD;
        power /= 2;
    }
    return answer;
}

void Precompute(int n) {
    factorial[0] = inverse[0] = 1;
    for (int i = 1; i <= n; i++)
        factorial[i] = (1LL * factorial[i - 1] * i) % MOD;
    inverse[n] = RaiseToPower(factorial[n], MOD - 2);
    for (int i = n - 1; i >= 1; i--)
        inverse[i] = (1LL * (i + 1) * inverse[i + 1]) % MOD;
}

int comb(int n, int k) {
    int answer = (1LL * inverse[n - k] * inverse[k]) % MOD;
    answer = (1LL * answer * factorial[n]) % MOD;
    return answer;
}

int code(char ch) {
    switch(ch) {
        case 'W' : return 0;
        case 'B' : return 1;
        case '?' : return 2;
        default: assert(false);
    }
}

int cnt[3][3];

int have(int x) {
    int ans = 0;
    for (int i = 0; i < 3; i++) {
        ans += cnt[i][x];
        if (i != x) {
            ans += cnt[x][i];
        }
    }
    return ans;
}

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

int ways(int n, int w, int b) {
    int lw = cnt[0][0] + cnt[0][1] + cnt[0][2];
    int lb = cnt[1][0] + cnt[1][1] + cnt[1][2];
    int rw = cnt[0][0] + cnt[1][0] + cnt[2][0];
    int rb = cnt[0][1] + cnt[1][1] + cnt[2][1];
    int lq = cnt[2][0] + cnt[2][1] + cnt[2][2];
    int rq = cnt[0][2] + cnt[1][2] + cnt[2][2];
    assert(lw + lb + lq == n && rw + rb + rq == n);
    assert(b >= lb && b >= rb && w >= lw && w >= rw);
    return 1LL * comb(lq, w - lw) * comb(rq, w - rw) % MOD;
}

int main() {
    timeBegin();
    //  ifstream cin("input.txt");
//    ofstream cout("answer.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    srand(time(0));
    int n;
    cin >> n;
    Precompute(n);
    for (int i = 1; i <= n; i++) {
        char l, r;
        cin >> l >> r;
        int cl = code(l), cr = code(r);
        if (cr != 2) {
            cr ^= 1;
        }
        cnt[cl][cr]++;
    }
    int ans = 0;
    // All white.
    if (!have(1)) {
        ans++;
    }
    // All black.
    if (!have(0)) {
        ans++;
    }
    // Fix w whites on a side
    int lw = cnt[0][0] + cnt[0][1] + cnt[0][2];
    int lb = cnt[1][0] + cnt[1][1] + cnt[1][2];
    int rw = cnt[0][0] + cnt[1][0] + cnt[2][0];
    int rb = cnt[0][1] + cnt[1][1] + cnt[2][1];
    for (int w = max(lw, rw); w + max(lb, rb) <= n; w++) {
        add(ans, ways(n, w, n - w));
    }
    if (!cnt[1][0] && !cnt[0][1]) {
        sub(ans, RaiseToPower(2,cnt[2][2]));
    }
    cout << ans << "\n";
    return 0;
}