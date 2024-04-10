#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<ciso646>
#include<random>
#include<map>
#include<set>
#include<bitset>
#include<stack>
#include<unordered_map>
#include<utility>
#include<cassert>
using namespace std;

//#define int long long
typedef long long ll;

typedef unsigned long long ul;
typedef unsigned int ui;
const ll mod = 1000000007;
const ll INF = mod * mod;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef pair<ll, ll> LP;
typedef vector<ll> vec;
typedef vector<string> svec;
typedef long double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-8;

void solve() {
	int n; cin >> n;
	vector<int> l(n), r(n);
	vector<P> v;
	rep(i, n) {
		cin >> l[i] >> r[i];
		v.push_back({ l[i],i });
	}
	sort(v.begin(), v.end());
	int m; cin >> m;
	vector<int> le(m), ri(m), k(m);
	vector<P> use;
	rep(i, m) {
		cin >> le[i] >> ri[i] >> k[i];
		use.push_back({ le[i],i });
	}
	sort(use.begin(), use.end());
	vector<int> ans(n);
	set<P> st;
	int loc = 0;
	rep(i, n) {
		while (loc < m&&use[loc].first <= v[i].first) {
			int id = use[loc].second;
			st.insert({ ri[id],id });
			loc++;
		}
		int cur= v[i].second;
		P p = { r[cur],-1 };
		st.insert(p);
		auto itr = st.find(p);
		itr++;
		if (itr == st.end()) {
			cout << "NO" << endl; return;
		}
		P u = *itr;
		st.erase(p);
		int id = u.second;
		ans[cur] = id;
		k[id]--;
		if (k[id] == 0) {
			st.erase({ ri[id],id });
		}
	}
	cout << "YES" << endl;
	rep(i, n) {
		if (i > 0)cout << " ";
		cout << ans[i] + 1;
	}
	cout << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//init();
	solve();
	//cout << "finish" << endl;
	//stop
	return 0;
}