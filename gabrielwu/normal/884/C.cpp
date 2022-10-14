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

	int n; cin >> n;
	vector<int> p(n);
	vector<bool> vis(n);
	forn(i, n) {
		cin >> p[i];
		p[i]--;
	}
	vector<ll> cyc;
	forn(i, n) {
		if(vis[i]) continue;
		vis[i] = true;
		int x = p[i];
		int s = 1;
		while(x != i) {
			vis[x] = true;
			x = p[x];
			s++;
		}
		cyc.pb(s);
	}

	sort(cyc.begin(), cyc.end(), greater<int>());
	if(cyc.size() == 1) {
		cout << cyc[0] * cyc[0];
	} else {
		ll ans = 0;
		ans += (cyc[0] + cyc[1]) * (cyc[0] + cyc[1]);
		for(int i=2; i<cyc.size(); i++){
			ans += cyc[i]*cyc[i];
		}
		cout << ans << "\n";
	}
}