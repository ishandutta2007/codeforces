#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

const int MOD = int(1e9) + 7;
int f[400005], rf[400005];

int binPow(LL x, int p) {
    LL res = 1;
    while (p) {
        if (p & 1) res = res * x % MOD;
        p >>= 1;
        if (p) x = x * x % MOD;
    }
    return (int)res;
}

LL c(int n, int k) {
    return (LL)f[n] * rf[k] % MOD * rf[n - k];
}

int n;
char s[200005];

int main() {
    f[0] = rf[0] = 1;
    for (int i = 1; i < 400005; ++i) {
        f[i] = (LL)f[i - 1] * i % MOD;
        rf[i] = binPow(f[i], MOD - 2);
    }
    scanf("%s", s);
    n = strlen(s);
    int a = 0, b = 0;
    forn(i, n) {
        b += (s[i] == ')');
    }
    int ans = 0;
    forn(i, n) if (s[i] == '(') {
        ++a;
        if (b > 0) {
            ans = (ans + c(a + b - 1, b - 1)) % MOD;
        }
    } else {
        --b;
    }
    cout << ans << endl;
    return 0;
}