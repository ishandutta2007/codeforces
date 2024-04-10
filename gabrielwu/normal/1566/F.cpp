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
typedef double ld;
typedef long double lld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<bool> vb;

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

	int t;
	cin >> t;
	bool bug = false;
	forn(ti, t){
		int n, m;
		cin >> n >> m;

		vector<ll> a(n);
		forn(i, n) cin >> a[i];
		// if(ti == 0 && a[0] == -725){
		// 	bug = true;
		// }
		vector<pll> seg(m);
		forn(i, m){
			ll l, r;
			cin >> l >> r;
			seg[i] = mp(l, r);
		}

		// if(ti == 8 && bug){
		// 	cout << n << " "<< m << " " << a << " "<< seg << "\n";
		// }

		vector<pll> s;
		forn(i, n){
			s.pb(mp(a[i], -MOD));
		}
		forn(i, m){
			s.pb(mp(seg[i].s, i));
		}

		// cout << seg << "\n";

		vector<vector<pll>> ints(n+1);
		sort(s.begin(), s.end());
		// cout << s << "\n";
		ll bef = -MOD;
		int ind = 0;
		for(pll x: s){
			if(x.s == -MOD){
				bef = x.f;
				ind++;
			} else {
				if(bef < seg[x.s].f) ints[ind].pb(seg[x.s]);
			}
		}

		sort(a.begin(), a.end());

		vector<ll> sing(n), doub(n);

		//0 case
		ll far = a[0];
		for(pll x: ints[0]){
			ckmin(far, x.s);
		}
		sing[0] = a[0] - far;
		doub[0] = 2*(a[0] - far);

		// cout << ints << "\n";
		// cout << a << endl;

		for(int i=1; i<n; i++){
			if(ints[i].size() == 0){
				sing[i] = sing[i-1];
				doub[i] = sing[i-1];
				continue;
			}

			multiset<ll> r;
			for(pll seg: ints[i]){
				r.insert(seg.s);
			}
			// cout << i << " " << sing << " "<< doub << endl;

			sort(ints[i].begin(), ints[i].end());
			assert(sing[i-1] <= doub[i-1]);
			sing[i] = sing[i-1] + a[i] - *(r.lower_bound((ll) -MOD));
			doub[i] = sing[i-1] + (a[i] - *(r.lower_bound((ll) -MOD)))*2;

			for(int j=0; j<((int)ints[i].size())-1; j++){
				r.erase(r.lower_bound(ints[i][j].s));
				ckmin(sing[i], sing[i-1] + 2*(ints[i][j].f - a[i-1]) + (a[i] - *(r.lower_bound((ll) -MOD))));
				ckmin(sing[i], doub[i-1] + (ints[i][j].f - a[i-1]) + (a[i] - *(r.lower_bound((ll) -MOD))));
				ckmin(doub[i], sing[i-1] + 2*(ints[i][j].f - a[i-1]) + 2*(a[i] - *(r.lower_bound((ll) -MOD))));
				ckmin(doub[i], doub[i-1] + (ints[i][j].f - a[i-1]) + 2*(a[i] - *(r.lower_bound((ll) -MOD))));
			}
			// cout << i << " " << sing[i] << " " << doub[i] << "\n";
			ckmin(sing[i], sing[i-1] + 2*(ints[i].back().f - a[i-1]));
			ckmin(sing[i], doub[i-1] + (ints[i].back().f - a[i-1]));
			ckmin(doub[i], sing[i-1] + 2*(ints[i].back().f - a[i-1]));
			// cout << i << " " << sing[i] << " " << doub[i] << " " << ints[i].back() << "\n";
			ckmin(doub[i], doub[i-1] + (ints[i].back().f - a[i-1]));
		}

		// cout << sing << "\n";
		// cout << doub << endl;

		far = a[n-1];
		for(pll x: ints[n]){
			ckmax(far, x.f);
		}
		ll ans = min(sing[n-1] + 2*(far - a[n-1]), doub[n-1] + far - a[n-1]);
		cout << ans << endl;


	}
}

/*
2 33 [-281, 725]
[(-554, -463), (-518, -330), (-925, -502), (-281, -281), (798, 931), (738, 844), (-281, -281), (733, 743), (728, 733), (-959, -649), (727, 811), (756, 915), (-281, -281), (944, 996), (-281, -281), (-281, -281), (-473, -427), (867, 977), (-281, -281), (-281, -281), (903, 950), (-798, -593), (-971, -805), (-281, -281), (-729, -620), (755, 820), (-281, -281), (880, 982), (-281, -281), (742, 774), (-281, -281), (735, 781), (-281, -281)]
*/