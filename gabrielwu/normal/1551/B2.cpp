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
		int n, k;
		cin >> n >> k;
		vector<pii> v(n);
		forn(i, n){
			int x;
			cin >> x;
			v[i] = mp(x, i);
		}
		sort(v.begin(), v.end());
		vector<int> last(k, -1);
		vector<int> ans(n);
		int curr = 0;
		forn(i, n){
			if(last[curr] != v[i].f){
				ans[v[i].s] = curr+1;
				last[curr] = v[i].f;
				curr = (curr+1)%k;
			}
		}
		vector<bool> skipped(k);
		forn(i, n){
			if(ans[i] > 0 && ans[i]-1 < curr){
				if(!skipped[ans[i]]){
					skipped[ans[i]] = true;
					cout << "0 ";
				}else{
					cout << ans[i] << " ";
				}
			}else{
				cout << ans[i] << " ";
			}
		}
		cout << "\n";
	}
}