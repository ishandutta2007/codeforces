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
	forn(ti, t){
		int n, m;
		cin >> n >> m;
		vector<int> r(n);
		forn(i, n) cin >> r[i];
		vector<vector<bool>> v(n, vector<bool>(m));
		forn(i, n){
			forn(j, m){
				char c;
				cin >> c;
				v[i][j] = (c == '1');
			}
		}
		ll best = -1;
		int bb;
		forn(b, (1 << n)){
			vector<pii> weight(m);
			forn(i, m){
				weight[i].s = i;
			}

			ll ans = 0;
			forn(i, n){
				if((b>>i)&1){
					ans -= r[i];
				} else {
					ans += r[i];
				}
				forn(j, m){
					if(v[i][j]){
						if((b>>i)&1){
							weight[j].f++;
						} else {
							weight[j].f--;
						}
					}
				}
			}

			sort(weight.begin(), weight.end());
			forn(i, m){
				ans += weight[i].f*(i+1);
			}
			if(ans > best){
				best = ans;
				bb = b;
			}
		}

		// cout << bb << "\n";

		vector<pii> weight(m);
		forn(i, m){
			weight[i].s = i;
		}

		forn(i, n){
			forn(j, m){
				if(v[i][j]){
					if((bb>>i)&1){
						weight[j].f++;
					} else {
						weight[j].f--;
					}
				}
			}
		}
		sort(weight.begin(), weight.end());
		vector<int> ans(m);
		forn(i, m){
			ans[weight[i].s] = i+1;
		}
		forn(i, m) cout << ans[i] << " ";
		cout << "\n";
	}
}