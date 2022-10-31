#include <bits/stdc++.h>
 
using namespace std;
 
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define sz(x) (int) ((x).size())
#define forn(i, n) for (int i = 0; i < (n); ++i)
#define fornr(i, n) for (int i = (n) - 1; i >= 0; --i)
#define forab(i, a, b) for (int i = (a); (i) < (b); ++i)
#define all(c) (c).begin(), (c).end()
 
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

const int N = 1e6 + 100;
const ll INF = 1e18;

int n;
ll a[N], b[N], toRight[N], cntRight[N];

ll solve(ll p) {
	forn(i, n) {
		b[i] = a[i] % p;
	}
	fornr(i, n) {
		toRight[i] = toRight[i + 1] + cntRight[i + 1];
		cntRight[i] = cntRight[i + 1] + b[i];
	}
	ll ans = toRight[0];
	forab(i, 1, n) {
		ll moved = cntRight[i];
		ans -= moved / p * p;
		ll left = cntRight[i] % p;
		if (p - left < left) {
			ans -= left;
			ans += p - left;
		}
	}
	return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	cin >> n;
	ll sum = 0;
	forn(i, n) {
		cin >> a[i];
		sum += a[i];
	}
//	cerr << sum << '\n';
	if (sum == 1) {
		cout << -1 << '\n';
		return 0;
	}
	vector<ll> primes;
	for(ll i = 2; i * i <= sum; i++) {
		if (sum % i == 0) {
			primes.pb(i);
//			cerr << i << " " ;
			while(sum % i == 0) {
				sum /= i;
			}
		}
	}
	if (sum > 1) {
		primes.pb(sum);
//		cerr << sum << " ";
	}
//	cerr << '\n';
	ll ans = INF;
	for(ll p : primes) {
		ans = min(ans, solve(p));
	}
	cout << ans << '\n';
    return 0;
}