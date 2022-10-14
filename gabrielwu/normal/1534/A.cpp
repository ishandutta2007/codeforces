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
		int n, m;
		cin >> n >> m;
		bool r = false, w = false;
		forn(i, n){
			forn(j, m){
				char c;
				cin >> c;
				if(c == 'R'){
					if((i+j)%2 == 0) r = true;
					else w = true;
				} else if(c == 'W'){
					if((i+j)%2 == 0) w = true;
					else r = true;
				}
			}
		}
		if(r && w){
			cout << "NO\n";
		}else{
			cout << "YES\n";
			if(r){
				forn(i, n){
					forn(j, m){
						if((i+j)%2) cout << 'W';
						else cout << 'R';
					}cout << "\n";
				}
			}else{
				forn(i, n){
					forn(j, m){
						if((i+j)%2) cout << 'R';
						else cout << 'W';
					}cout << "\n";
				}

			}
		}
	}
}