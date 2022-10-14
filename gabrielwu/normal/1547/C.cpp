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
		int k, n, m;
		cin >> k >> n >> m;
		vector<int> a(n), b(m);
		forn(i, n) cin >> a[i];
		forn(i, m) cin >> b[i];
		a.pb(MOD);
		b.pb(MOD);


		vector<int> ans;
		int i=0, j=0;
		bool works = true;
		forn(x, n+m){
			if(a[i] == 0){
				ans.pb(0);
				i++;
				k++;
			}else if(b[j] == 0){
				ans.pb(0);
				j++;
				k++;
			}else if(a[i] < b[j]){
				works &= a[i] <= k;
				ans.pb(a[i]);
				i++;
			}else{
				works &= b[j] <= k;
				ans.pb(b[j]);
				j++;
			}
		}
		if(works){
			forn(i, n+m){
				cout << ans[i] << " ";
			}
			cout << "\n";
		}else{
			cout << "-1\n";
		}
	}
}