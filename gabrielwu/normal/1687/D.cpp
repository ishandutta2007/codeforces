#include <bits/stdc++.h>
using namespace std;

#define forn(i, n) for (int i = 0; i < (n); i++)
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define f first
#define s second
#define rand(i, j) uniform_int_distribution<ll>((ll)(i), (ll)(j))(rng)
mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

template<typename A, typename B> ostream& operator<<(ostream &cout, pair<A, B> const &p) { return cout << "(" << p.f << ", " << p.s << ")"; }
template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v) {
	cout << "["; for (int i = 0; i < (int)v.size(); i++) {if (i) cout << ", "; cout << v[i]; } return cout << "]";
}
template<typename T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<typename T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }


//2 147 483 647 int max
//9 223 372 036 854 775 807 ll max


int main(){
	cin.tie(0)->sync_with_stdio(0);

	int n;
	cin >> n;

	vector<ll> v(n);
	forn(i, n) cin >> v[i];

	bool already = true;
	forn(i, n) {
		ll x = sqrt(v[i]);
		if(v[i] - x*x > x) {
			already = false;
			break;
		}
	}

	if(already) {
		cout << 0 << "\n";
		return 0;
	}

	ll MX = 5e6+5;
	vector<ll> qmin(MX, -1), qmax(MX, MOD);
	forn(i, n) {
		qmin[v[i]] = v[i];
		qmax[v[i]] = v[i];
	}
	for(int i=1; i<MX; i++) {
		if(qmin[i] == -1) qmin[i] = qmin[i-1];
	}
	for(int i=MX-2; i>=0; i--) {
		if(qmax[i] == MOD) qmax[i] = qmax[i+1];
	}



	ll base = 1;
	for(ll base = 1; base <= MX; base++) {
		ll l = max(0LL, base*base - v[0]);
		ll r = base*(base+1)-v[0];

		if(r < 0) continue;

		ll def = l;
		// cout << base << endl;
		// cout << def << endl;
		for(ll iv = base;; iv++) {
			if(iv*iv > v.back()+def) break;
			//check bottom
			ll nextguy = qmax[iv*(iv+1)+1 - def]+def;
			ckmax(l, def + (iv+1)*(iv+1) - nextguy);

			//check top
			ll prevguy = qmin[iv*(iv+1) - def]+def;
			ckmin(r, def + (iv*(iv+1)) - prevguy);

			// cout << iv << " " << nextguy << " " << prevguy << " " << l << " " << r << endl;

			if(l > r) break;
		}

		if(l <= r) {
			cout << l << "\n";
			return 0;
		}
	}

	assert(0);
}