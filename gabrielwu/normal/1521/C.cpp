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
		vector<int> cand;
		for(int i=0; i<n-1; i+=2){
			cout << "? 2 " << i+1 << " " << i+2 << " 1" << endl;
			int x;
			cin >> x;
			if(x == 1 || x == 2){
				cand.pb(i);
				cand.pb(i+1);
			}
		}
		if(n%2 == 1){
			cout << "? 2 " << n-1 << " " << n << " 1" << endl;
			int x;
			cin >> x;
			if(x == 1 || x == 2){
				cand.pb(n-2);
				cand.pb(n-1);
			}
		}

		int one = -1;
		for(int x: cand){
			cout << "? 2 " << x+1 << " " << (x+1)%n+1 << " 1" << endl;
			int y; cin >> y;
			if(y == 1){
				one = x;
				break;
			}
		}

		vector<int> v(n);
		v[one] = 1;
		forn(i, n){
			if(i == one) continue;
			cout << "? 1 " << one+1 << " " << i+1 << " " << n-1 << endl;
			cin >> v[i];
		}
		cout << "! ";
		forn(i, n) cout << v[i] << " ";
		cout << endl;
	}
}