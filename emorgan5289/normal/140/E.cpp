#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int inf = 1e9;
const ll inf_ll = 1e18;
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifndef LOCAL
#define debug(...)
#else
#include "../../debug.cpp"
#endif

template<typename T>
T inv(T a, T m) {
    T r = 1;
    for (T k = m-2; k; k >>= 1) {
        if (k&1) r = (r*a)%m;
        a = (a*a)%m;
    }
    return r%m;
}

template<typename T>
T choose(T n, T k, T m) {
    T a = 1, b = 1, r = n;
    k = min(k, n-k);
    for (T d = 1; d <= k; d++, r--) {
        a = (a*r)%m;
        b = (b*d)%m;
    }
    return (a*inv(b, m))%m;
}

const ll N = 1e6+5, L = 5e3+5;
int c[L][L];
ll f[N], l[N], s[N], ch[N];
vector<ll> dp[N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n, m, p; cin >> n >> m >> p;
    f[0] = c[0][0] = ch[0] = 1;
    for (ll i = 1; i < N; i++) {
        f[i] = f[i-1]*i%p;
        ch[i] = ch[i-1]*(m-i+1)%p;
    }
    for (ll i = 1; i < L; i++)
        for (ll j = 1; j < L; j++)
            c[i][j] = ((j-1)*ll(c[i-1][j]) + ll(c[i-1][j-1]))%p;
    s[0] = 1;
    for (ll i = 1; i <= n; i++) {
        cin >> l[i];
        dp[i].assign(l[i]+1, 0);
        for (ll j = 1; j <= min(m, l[i]); j++) {
            dp[i][j] = ll(c[l[i]][j])*s[i-1]%p;
            if (j <= l[i-1]) dp[i][j] = (dp[i][j]-ll(c[l[i]][j])*f[j]%p*dp[i-1][j]%p+p)%p;
            s[i] = (s[i]+dp[i][j]*ch[j])%p;
        }
    }
    cout << s[n] << "\n";
}