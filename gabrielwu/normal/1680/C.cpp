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

	int t;
	cin >> t;
	forn(ti, t){
		string s;
		cin >> s;

		int n = s.size();
		int ones = 0;
		forn(i, n) {
			ones += s.at(i) == '1';
		}

		int lo = 0, hi = n;
		while(lo < hi) {
			int mid = (lo + hi)/2;

			int i = 0, j = 0;
			int zc = 0, oc = 0;
			bool works = false;
			while(i < n) {
				if(max(zc, ones-oc) <= mid) {
					works = true;
					break;
				}
				while(j < n && (zc + (s.at(j) == '0') <= mid)) {
					zc += s.at(j) == '0';
					oc += s.at(j) == '1';
					j++;
					if(max(zc, ones-oc) <= mid) {
						works = true;
						break;
					}
				}
				if(works) break;

				zc -= s.at(i) == '0';
				oc -= s.at(i) == '1';
				i++;
				ckmax(j, i);
				if(j == i) {
					zc = 0;
					oc = 0;
				}
			}

			if(works) {
				hi = mid;
			} else {
				lo = mid+1;
			}
		}
		cout << lo << "\n";
	}
}