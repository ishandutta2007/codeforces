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

//2 147 483 647 int max
//9 223 372 036 854 775 807 ll max


int main(){
	cin.tie(0)->sync_with_stdio(0);

	int t;
	cin >> t;
	forn(ti, t){
		int n;
		cin >> n;

		vector<int> a(n);
		vector<int> cnt(n);
		vector<int> bad, unused;
		vector<int> locs;
		forn(i, n){
			cin >> a[i];
			a[i]--;
			if(cnt[a[i]]++){
				locs.pb(i);
			}
		}
		forn(i, n){
			if(cnt[i] == 0){
				unused.pb(i);
			} else if(cnt[i] > 1){
				bad.pb(i);
			}
		}
		int ans = n;
		if(bad.size() == 1 && unused.size() == 1){
			forn(i, n){
				if(a[i] == bad[0] && i != unused[0]){
					a[i] = unused[0];
					ans--;
					break;
				}
			}
		}else{
			assert(unused.size() == locs.size());
			set<int> in;
			for(int x: unused){
				in.insert(x);
			}
			set<int> both;
			vector<int> u2, l2;
			for(int x: locs){
				if(in.find(x) != in.end()){
					both.insert(x);
					u2.pb(x);
					l2.pb(x);
				}
			}

			for(int x: unused){
				if(both.find(x) == both.end()){
					u2.pb(x);
				}
			}
			for(int x: locs){
				if(both.find(x) == both.end()){
					l2.pb(x);
				}
			}
			// cout << u2 << " " << l2 << "\n";
			assert(u2.size() != 1 && u2.size() == l2.size());
			forn(i, u2.size()){
				a[l2[i]] = u2[(i+1)%u2.size()];
				ans--;
			}
		}

		cout << ans << "\n";
		forn(i, n){
			cout << a[i]+1 << " ";
		}cout << "\n";
	}
}