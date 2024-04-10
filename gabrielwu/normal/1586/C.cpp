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

	int n, m;
	cin >> n >> m;
	vector<int> pref(m);

	vector<vector<bool>> a(n, vector<bool>(m));
	vector<bool> b(m-1);
	forn(i, n){
		forn(j, m){
			char c;
			cin >> c;
			if(c == 'X') a[i][j] = true;
		}
	}

	for(int i=1; i<n; i++){
		for(int j=1; j<m; j++){
			b[j-1] = b[j-1] || (a[i-1][j] && a[i][j-1]);
		}
	}

	forn(j, m-1){
		pref[j+1] = pref[j] + b[j];
	}

	int q;
	cin >> q;
	forn(qi, q){
		int x, y;
		cin >> x >> y;
		if(pref[y-1] - pref[x-1] > 0){
			cout << "NO\n";
		} else {
			cout << "YES\n";
		}
	}
}