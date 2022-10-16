#ifdef LOCAL
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)
#define rep(i, a, b) for(int i = a; i < (b); ++i)

typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<long long> vi;

const int mod = 1000000007;
long long p2[30];

void FST(vi& a, bool inv) {
	for (int n = sz(a), step = 1; step < n; step *= 2) {
		for (int i = 0; i < n; i += 2 * step) rep(j,i,i+step) {
			ll &u = a[j], &v = a[j + step]; tie(u, v) =
				pii(u + v, u - v);
		}
	}
	if (inv) for (ll& x : a) x /= sz(a);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    p2[0] = 1;
    for (int i = 1; i <= 25; i++) p2[i] = (p2[i-1]+p2[i-1])%mod;

    int n; string s;
    cin >> n >> s;

    vi a(sz(s));
    for (int i = 0; i < (1<<n); i++) {
        a[i] = s[i]-'0';
    }

    FST(a,false);
    for (int i = 0; i < sz(a); i++) {
        a[i] = (a[i]*1ll*a[i]);
    }
    FST(a,true);

    
    long long ans = 0;
    for (int i = 0; i < sz(a); i++) {
        ans = (ans + a[i] * p2[n-__builtin_popcount(i)]) % mod;
    }

    ans = (ans * 3) % mod;
    cout << ans << endl;
    return 0;
}