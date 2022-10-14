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
struct custom_hash {
	static uint64_t splitmix64(uint64_t x) {
		x += 0x9e3779b97f4a7c15;
		x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
		x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
		return x ^ (x >> 31);
	}
	size_t operator()(uint64_t x) const {
		static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
		return splitmix64(x + FIXED_RANDOM);
	}
};

int main(){
	cin.tie(0)->sync_with_stdio(0);

	const int LG = 30;

	int t;
	cin >> t;
	forn(ti, t) {
		int n; cin >> n;
		vector<int> a(n), b(n);
		forn(i, n) cin >> a[i];
		forn(i, n) {
			cin >> b[i];
			b[i] = (1<<30) - 1 - b[i];
		}

		int ans = 0;
		for(int j=LG-1; j>=0; j--) {
			int mid = ans + (1<<j);

			//try mid
			unordered_map<int, int, custom_hash> cnt;
			forn(i, n) {
				cnt[a[i] & mid]++;
				cnt[b[i] & mid]--;
			}

			bool works = true;
			for(auto p: cnt) {
				if(p.s != 0) {
					works = false;
					break;
				}
			}

			if(works) ans = mid;
		}

		cout << ans << "\n";

		// vector<unordered_map<int, int, custom_hash>> cnts(LG);
		// forn(i, n) {
		// 	int res = 0;
		// 	for(int j = LG-1; j>=0; j--) {
		// 		res += b[i] & (1<<j);
		// 		cnts[j][res]++;
		// 	}
		// }


	}
}