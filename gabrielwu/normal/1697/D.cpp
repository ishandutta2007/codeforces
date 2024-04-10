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

char q1(int i) {
	cout << "? " << 1 << " " << i+1 << endl;
	char c; cin >> c;
	return c;
}

int q2(int l, int r) {
	cout << "? " << 2 << " "<< l+1 << " " << r+1 << endl;
	int x; cin >> x;
	return x;
}

int main(){
	cin.tie(0)->sync_with_stdio(0);

	int n; cin >> n;

	if(n == 1) {
		char x = q1(0);
		cout << "! " << x << endl;
		return 0;
	}

	vector<int> pref(n);
	pref[0] = 1;
	for(int i=1; i<n; i++) {
		pref[i] = q2(0, i);
	}

	vector<int> firsts;
	firsts.pb(0);
	forn(i, n-1) {
		if(pref[i] != pref[i+1]) {
			assert(pref[i] + 1 == pref[i+1]);
			firsts.pb(i+1);
		}
	}
	int k = firsts.size();	//# distinct in total
	assert(pref[n-1] == k);
	vector<char> v(k);
	forn(i, k) v[i] = q1(firsts[i]);

	vector<int> last(k, -1);
	vector<int> ans(n);
	for(int i=0; i<n; i++) {
		bool found = false;
		forn(j, k) {
			if(firsts[j] == i) {
				last[j] = i;
				ans[i] = j;
				found = true;
				break;
			}
		}
		if(found) continue;

		vector<pii> avail;
		forn(j, k) {
			if(last[j] != -1) {
				avail.pb({last[j], j});
			}
		}
		sort(avail.begin(), avail.end(), greater<pii>());
		int lo = 0, hi = avail.size()-1;
		while(lo < hi) {
			int mid = (lo + hi)/2;
			int q = q2(avail[mid].f, i);
			int should = mid+2;
			if(q != should) {
				assert(q+1 == should);
				hi = mid;
			} else {
				lo = mid+1;
			}
		}

		ans[i] = avail[lo].s;
		last[avail[lo].s] = i;
	}

	cout << "! ";
	forn(i, n) cout << v[ans[i]];
	cout << endl;
}