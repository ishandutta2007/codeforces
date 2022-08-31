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
const ll mod = 998244353;
const ll INF = mod;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef pair<ll, ll> LP;
typedef vector<LP> vec;
typedef vector<string> svec;
typedef long double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-8;

const int sz = 2003;
bool isp[2003];
void init() {
	fill(isp + 2, isp + sz, true);
	for (int i = 2; i < sz; i++) {
		if (!isp[i])continue;
		for (int j = 2 * i; j < sz; j += i) {
			isp[j] = false;
		}
	}
}

void solve() {

	int n;	cin >> n;
	vector<P> ans;
	rep1(i, n-1) {
		ans.push_back({ i, i + 1 });
	}
	ans.push_back({ 1,n });
	int m = n; int loc = 1;
	while (!isp[m]) {
		if (loc + 2 > n) {
			cout <<n<<" "<< "No" << endl; return;
		}
		ans.push_back({ loc,loc + 2 });
		m++; loc++;
		if (loc % 2)loc += 2;
	}
	//return;
	cout << m << endl;
	rep(i, m) {
		cout << ans[i].first << " " << ans[i].second << endl;
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	init();
	solve();
	/*for (int i = 3; i <= 1000; i++) {
		solve(i);
	}*/
	//cout << "finish" << endl;
	//stop
	return 0;
}