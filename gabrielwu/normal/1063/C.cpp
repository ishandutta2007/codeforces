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
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

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

	int n;
	cin >> n;

	ll lo1 = 0, lo2 = 0, hi1 = 1e9;
	ll hi2 = 1000000000;
	int a = n/2;
	int b = n-a;
	forn(i, a) {
		ll mid = (lo1 + hi1)/2;
		cout << 0 << " "<< mid << endl;
		string s;
		cin >> s;
		if(s == "black") {
			hi1 = mid;
		} else {
			lo1 = mid;
		}
	}
	forn(i, b) {
		ll mid = (lo2 + hi2)/2;
		cout << 1 << " "<< mid << endl;
		string s;
		cin >> s;
		if(s == "black") {
			hi2 = mid;
		} else {
			lo2 = mid;
		}
	}
	cout << 0 << " " << hi1-1 << " " << 1 << " "<< hi2-1 << endl;
}