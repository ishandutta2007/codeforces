#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

const int MOD = int(1e9) + 7;
int a, b, h;

int binPow(LL x, int p) {
    LL res = 1;
    while (p) {
        if (p & 1) res = res * x % MOD;
        p >>= 1;
        if (p) x = x * x % MOD;
    }
    return int(res);
}

int f[222222], rf[222222];

int c(int n, int k) {
    return (LL)f[n] * rf[k] % MOD * rf[n - k] % MOD;
}

int countGood() {
    int res = 0;
    for (int ca = 1; ca <= a; ++ca) {
        for (int cb = ca - 1; cb <= ca + 1; ++cb) {
            if (cb < 1 || (LL)cb * h > b) {
                continue;
            }
            int mul = ((ca == cb) ? 2 : 1);
            res = (res + (LL)mul * c(a - 1, ca - 1) * c(b - cb * h + cb - 1, cb - 1)) % MOD;
        }
    }
    return res;
}

int countTotal() {
    int res = 0;
    for (int ca = 1; ca <= a; ++ca) {
        for (int cb = ca - 1; cb <= ca + 1; ++cb) {
            if (cb < 1 || cb > b) {
                continue;
            }
            int mul = ((ca == cb) ? 2 : 1);
            res = (res + (LL)mul * c(a - 1, ca - 1) * c(b - 1, cb - 1)) % MOD;
        }
    }
    return res;
}

int main() {
    f[0] = rf[0] = 1;
    for (int i = 1; i < 222222; ++i) {
        f[i] = (LL)f[i - 1] * i % MOD;
        rf[i] = binPow(f[i], MOD - 2);
    }
    cin >> a >> b >> h;
    ++h;
    if (a == 0) {
        if (b >= h) {
            cout << 1 << endl;
        } else {
            cout << 0 << endl;
        }
        return 0;
    }
    if (b == 0) {
        cout << 1 << endl;
        return 0;
    }
    int g = countGood();
    int tot = countTotal();
    g = (LL)g * binPow(tot, MOD - 2) % MOD;
    cout << g << endl;
    return 0;
}