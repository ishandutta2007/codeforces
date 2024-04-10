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
		int n;
		cin >> n;
		vector<vector<bool>> v(n, vector<bool>(5));
		forn(i, n){
			forn(j, 5){
				int x;
				cin >> x;
				v[i][j] = x;
			}
		}

		bool works = false;
		forn(i, 5){
			for(int j=i+1; j<5; j++){
				bool good = true;
				int a = 0, b = 0;
				forn(k, n){
					if(v[k][i] && v[k][j]){
						a++; b++;
					} else if(v[k][i]){
						a++;
					} else if(v[k][j]){
						b++;
					} else {
						good = false;
						break;
					}
				}
				if(good && a >= n/2 && b >= n/2){
					works = true;
				}
			}
		}
		if(works){
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
}