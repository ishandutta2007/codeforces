#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// DON'T USE THESE MACROS DURING ICPC PRACTICE
#define For(i,n) for (int i=0; i<n; i++)
#define FOR(i,a,b) for (int i=a; i<=b; i++)
#define Down(i,n) for (int i=n-1; i>=0; i--)
#define DOWN(i,a,b) for (int i=b; i>=a; i--)

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;
typedef complex<ld> pt;
typedef vector<pt> pol;
typedef vector<int> vi;

const char nl = '\n';
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;
const ld EPS = 1e-10;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N = 1<<18;
struct SegTree {
	int t[2*N], m[2*N];;
	void insert(int i, int v) {
		i+=N;
		t[i] = m[i] = v;
		for (i/=2; i>0; i/=2) {
			t[i] = max(t[2*i], t[2*i+1]);
			m[i] = min(m[2*i], m[2*i+1]);
		}
	}
	int qmax(int l, int r) {
		int res = -INF;
		for (l+=N, r+=N+1; l<r; l/=2, r/=2) {
			if (l&1) res = max(res, t[l++]);
			if (r&1) res = max(res, t[--r]);
		}
		return res;
	}
	int qmin(int l, int r) {
		int res = INF;
		for (l+=N, r+=N+1; l<r; l/=2, r/=2) {
			if (l&1) res = min(res, m[l++]);
			if (r&1) res = min(res, m[--r]);
		}
		return res;
	}
};

SegTree segt[2];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(10);

	map<char,int> cnt;
	cnt['A'] = 0;
	cnt['D'] = 1;
	cnt['S'] = 2;
	cnt['W'] = 3;

	int T;
	cin >> T;
	while (T--) {
		string s;
		cin >> s;
		int n = s.size();
		int d[2];
		d[0] = d[1] = 0;
		segt[0].insert(0, 0);
		segt[1].insert(0, 0);
		for (int i=0; i<n; i++) {
			d[cnt[s[i]]/2] += 1-2*(cnt[s[i]]%2);
			segt[0].insert(i+1, d[0]);
			segt[1].insert(i+1, d[1]);
			//cerr << i << " -> " << d[0] << ',' << d[1] << nl;
		}
		for (int i=0; i<=n; i++) {
			//cerr << segt[0].qmin(i,n) << " " << segt[0].qmax(i,n) << nl;
		}
		//cerr << nl;

		int h = segt[0].qmax(0,n) - segt[0].qmin(0,n) + 1;
		int v = segt[1].qmax(0,n) - segt[1].qmin(0,n) + 1;
		//cerr << "init h " << segt[0].qmax(0,n) << " - " << segt[0].qmin(0,n) << nl;
		//cerr << "init v " << segt[1].qmax(0,n) << " - " << segt[1].qmin(0,n) << nl;
		ll ans = (ll)h*v;
		//cerr << " -> " << ans << nl;
		for (int i=0; i<=n; i++) {
			//cerr << "after " << i << nl;
			int hmax, hmin;
			hmax = max(segt[0].qmax(0,i), 1+segt[0].qmax(i,n));
			hmin = min(segt[0].qmin(0,i), 1+segt[0].qmin(i,n));
			ans = min(ans, (ll)v*(hmax-hmin+1));
			//cerr << "hmax: " << hmax << "  hmin: " << hmin << nl;
			//cerr << " -> " << ans << nl;
			hmax = max(segt[0].qmax(0,i), -1+segt[0].qmax(i,n));
			hmin = min(segt[0].qmin(0,i), -1+segt[0].qmin(i,n));
			ans = min(ans, (ll)v*(hmax-hmin+1));
			//cerr << "hmax: " << hmax << "  hmin: " << hmin << nl;
			//cerr << " -> " << ans << nl;
			hmax = max(segt[1].qmax(0,i), 1+segt[1].qmax(i,n));
			hmin = min(segt[1].qmin(0,i), 1+segt[1].qmin(i,n));
			ans = min(ans, (ll)h*(hmax-hmin+1));
			//cerr << "hmax: " << hmax << "  hmin: " << hmin << nl;
			//cerr << " -> " << ans << nl;
			hmax = max(segt[1].qmax(0,i), -1+segt[1].qmax(i,n));
			hmin = min(segt[1].qmin(0,i), -1+segt[1].qmin(i,n));
			ans = min(ans, (ll)h*(hmax-hmin+1));
			//cerr << "hmax: " << hmax << "  hmin: " << hmin << nl;
			//cerr << " -> " << ans << nl;
			//cerr << nl;
		}
		cout << ans << nl;
		//cerr << " ------- " << nl;
	}

	return 0;
}