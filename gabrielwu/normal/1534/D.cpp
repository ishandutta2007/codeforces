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

	int n;
	cin >> n;
	cout << "? 1" << endl;
	int odd = 0, even = 0;
	int close = 0;
	vector<int> dist(n);
	forn(i, n){
		cin >> dist[i];
		if(dist[i]%2) odd++;
		else even++;
	}
	vector<pii> ans;
	if(odd < even){
		forn(i, n){
			if(dist[i]%2){
				cout << "? " << i+1 << endl;
				forn(j, n){
					int x;
					cin >> x;
					if(x == 1){
						ans.pb(mp(i+1, j+1));
					}
				}
			}
		}
	}else{
		forn(i, n){
			if(dist[i]==1) ans.pb(mp(1, i+1));
		}
		for(int i=1; i<n; i++){
			if(dist[i]%2 == 0){
				cout << "? " << i+1 << endl;
				forn(j, n){
					int x;
					cin >> x;
					if(x == 1){
						ans.pb(mp(i+1, j+1));
					}
				}
			}
		}
	}

	assert(ans.size() == n-1);
	cout << "!" << endl;
	forn(i, n-1){
		cout << ans[i].f << " " << ans[i].s << endl;
	}
}