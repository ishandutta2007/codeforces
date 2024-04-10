#include <bits/stdc++.h>

#define MOD 1000000007LL
#define LOGN 17
#define MAXN (1 << LOGN)

using namespace std;
typedef long long ll;
ll inv;

ll mypow(ll a, ll e) {
    if(!e) return 1;
    a %= MOD;
    if(e & 1) return (a * mypow(a*a, e / 2)) % MOD;
    return mypow(a*a, e / 2);
}

int T[2][2][2][2] = {
    { { {1,  1}, {1, -1} }, { {1,  1}, {1, -1} } },
    { { {0,  1}, {1,  1} }, { {-1, 1}, {1,  0} } }
};

void FFT(vector<ll> &a, int op, bool inverse = false) {
    int u1 = T[op][inverse][0][0], v1 = T[op][inverse][0][1];
    int u2 = T[op][inverse][1][0], v2 = T[op][inverse][1][1];

    for(int b = 0; b < LOGN; b++)
        for(int i = 0; i < MAXN; i++)
            if((i & (1 << b)) == 0) {
                ll u = a[i], v = a[i + (1 << b)];
                a[i]            = u*u1 + v*v1;
                a[i + (1 << b)] = u*u2 + v*v2;

                if(a[i] >= MOD) a[i] -= MOD;
                if(a[i] < 0)    a[i] += MOD;
                if(a[i + (1 << b)] >= MOD) a[i + (1 << b)] -= MOD;
                if(a[i + (1 << b)] < 0)    a[i + (1 << b)] += MOD;
            }

	if (op == 0 && inverse)
		for (int i=0; i<a.size(); i++)
            a[i] = (a[i] * inv) % MOD;
}

vector<ll> convolution(vector<ll> a, vector<ll> b, int op) {
    FFT(a, op, false);
    FFT(b, op, false);
    for(int i=0; i<a.size(); i++) {
        a[i] = (a[i] * b[i]) % MOD;
    }
    FFT(a, op, true);
    return a;
}

vector<ll> other_convolution(vector<ll> a) {
    vector<ll> ret(MAXN);
    for(int mask = 0; mask < MAXN; mask++)
        for(int subset = mask;; subset = (subset-1) & mask) {
            ret[mask] = (ret[mask] + a[subset]*a[mask^subset]) % MOD;
            if(!subset) break;
        }
    return ret;
}

vector<ll> a(MAXN), b(MAXN), c(MAXN), fib(MAXN);
int n, x;

int main() {
    fib[1] = 1;
    for(int i = 2; i < MAXN; i++)
        fib[i] = (fib[i-2] + fib[i-1]) % MOD;
    inv = mypow(MAXN, MOD - 2);

    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &x);
        b[x]++;
    }

    c = convolution(b, b, 0);
    a = other_convolution(b);

    for(int i = 0; i < MAXN; i++) {
        a[i] = (a[i] * fib[i]) % MOD;
        b[i] = (b[i] * fib[i]) % MOD;
        c[i] = (c[i] * fib[i]) % MOD;
    }

    a = convolution(a, b, 1);
    a = convolution(a, c, 1);

    ll sum = 0;
    for(int i = 0; i < LOGN; i++) {
        sum = (sum + a[1 << i])% MOD;
    }

    printf("%lld\n", sum);
    return 0;
}