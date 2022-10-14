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

int x(int a){
	int ans = 0;
	while(a > 0 && a%4 != 3){
		ans ^= a;
		a--;
	}
	return ans;
}
int main(){
	cin.tie(0)->sync_with_stdio(0);

	int t;
	cin >> t;

	forn(ti, t){
		int a, b;
		cin >> a >> b;
		int bef = x(a-1);
		int ans = a;
		// cout << bef << " ";
		if(bef == b){
			// cout << "x" << "\n";
			ans += 0;
		} else if((bef ^ b) != a){
			// cout << "y" << "\n";
			ans++;
		} else {
			// cout << "z" << "\n";
			ans += 2;
		}
		cout << ans << "\n";
	}
}