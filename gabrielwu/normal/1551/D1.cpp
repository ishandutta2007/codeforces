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
		int n, m, k;
		cin >> n >> m >> k;
		function<char(int,int)> c = [&](int i, int j){
			return (char) ((5*i + j)%26 + 'a');
		};
		if(n%2 == 0 && m%2 == 0){
			vector<vector<char>> v(n, vector<char>(m));
			if(k%2){
				cout << "NO\n";
			}else{
				cout << "YES\n";
				for(int i=0; i<n; i+=2){
					forn(j, m){
						v[i][j] = c(i, j);
						v[i+1][j] = c(i, j);
					}
				}
				for(int i=0; i<n; i+=2){
					for(int j=0; j<m; j+=2){
						if(k > 0){
							k -= 2;
							swap(v[i+1][j], v[i][j+1]);
						}
					}
				}
			}
		} else if(n%2 == 0 && m%2 == 1){
			vector<vector<char>> v(n, vector<char>(m));
			if(k%2 || k > m/2 * n){
				cout << "NO\n";
			}else{
				cout << "YES\n";
				for(int i=0; i<n; i+=2){
					forn(j, m){
						v[i][j] = c(i, j);
						v[i+1][j] = c(i, j);
					}
				}
				for(int i=0; i<n; i+=2){
					for(int j=0; j<m-1; j+=2){
						if(k > 0){
							k -= 2;
							swap(v[i+1][j], v[i][j+1]);
						}
					}
				}
			}
		} else if(n%2 == 1 && m%2 == 0){
			k = (n*m/2)-k;
			swap(n, m);
			vector<vector<char>> v(n, vector<char>(m));
			if(k%2 || k > m/2 * n){
				cout << "NO\n";
			}else{
				cout << "YES\n";
				for(int i=0; i<n; i+=2){
					forn(j, m){
						v[i][j] = c(i, j);
						v[i+1][j] = c(i, j);
					}
				}
				for(int i=0; i<n; i+=2){
					for(int j=0; j<m-1; j+=2){
						if(k > 0){
							k -= 2;
							swap(v[i+1][j], v[i][j+1]);
						}
					}
				}
			}

		}
	}
}