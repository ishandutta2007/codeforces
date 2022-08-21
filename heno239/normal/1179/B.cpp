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
typedef vector<int> vec;
typedef vector<string> svec;
typedef long double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-8;

void solve() {
	int n, m; cin >> n >> m;
	if (n == 1 && m == 1) {
		cout << "1 1" << endl; return;
	}
	vector<P> ans;
	int lx = 1, ly = 1;
	int rx = n, ry = m;
	while (true) {
		ans.push_back({ lx,ly });
		ans.push_back({ rx,ry });
		ly++; if (ly > m)lx = lx + 1, ly = 1;
		if (lx == rx && ly == ry)break;
		ry--; if (ry == 0)rx = rx - 1, ry = m;
		if (lx == rx && ly == ry) {
			ans.push_back({ lx,ly }); break;
		}
	}
	rep(i, ans.size()) {
		printf("%d %d\n", ans[i].first, ans[i].second);
	}
}

signed main() {
	//cout << fixed << setprecision(10);
	//init();
	solve();
	//stop
	return 0;
}