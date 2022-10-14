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

	string s;
	cin >> s;
	vector<vector<int>> pref(6, vector<int>(n+1));
	forn(i, n){
		forn(j, 6){
			pref[j][i+1] = pref[j][i];
		}
		if(s.at(i) == 'a'){
			if(i%3 == 0){
				pref[0][i+1]++;
				pref[1][i+1]++;
			} else if(i%3 == 1){
				pref[2][i+1]++;
				pref[4][i+1]++;
			} else if(i%3 == 2){
				pref[3][i+1]++;
				pref[5][i+1]++;
			}
		} else if(s.at(i) == 'b'){
			if(i%3 == 0){
				pref[2][i+1]++;
				pref[3][i+1]++;
			} else if(i%3 == 1){
				pref[0][i+1]++;
				pref[5][i+1]++;
			} else if(i%3 == 2){
				pref[1][i+1]++;
				pref[4][i+1]++;
			}
		} else if(s.at(i) == 'c'){
			if(i%3 == 0){
				pref[4][i+1]++;
				pref[5][i+1]++;
			} else if(i%3 == 1){
				pref[1][i+1]++;
				pref[3][i+1]++;
			} else if(i%3 == 2){
				pref[0][i+1]++;
				pref[2][i+1]++;
			}
		}
	}
	// cout << "HERE" << endl;

	forn(mi, m){
		int best = 0;
		int l, r;
		cin >> l >> r;
		l--; r--;
		forn(i, 6){
			ckmax(best, pref[i][r+1] - pref[i][l]);
		}
		cout << r-l+1-best << "\n";
	}
}