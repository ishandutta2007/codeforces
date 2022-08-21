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
#include<complex>
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
typedef long double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-5;
const ld pi = acos(-1.0);



void solve() {
	int n; cin >> n;
	vector<int> a(n);
	vector<P> v;
	rep(i, n) {
		cin >> a[i];
		v.push_back({ a[i],i });
	}
	sort(v.begin(), v.end(), greater<P>());
	vector<P> ans;
	int len = v[0].first;
	vector<int> memo;
	int root = 2 * v[0].second;
	memo.push_back(2*v[0].second);
	rep1(i, len - 1) {
		int las = memo.back();
		int nex = 2 * v[i].second;
		ans.push_back({ las,nex });
		memo.push_back(nex);
	}
	rep(i, n) {
		if (i <= len - 1) {
			int loc = i + v[i].first-1;
			ans.push_back({ memo[loc],2 * v[i].second + 1 });
			if (loc + 1 == memo.size()) {
				memo.push_back(2 * v[i].second + 1);
			}
		}
		else {
			int cur = 2*v[i].second;
			ans.push_back({ root,cur });
			if (v[i].first == 1) {
				ans.push_back({ cur,cur + 1 });
			}
			else {
				ans.push_back({ cur+1,memo[v[i].first - 2] });
			}
		}
	}
	rep(i, 2*n-1) {
		cout << ans[i].first+1 << " " << ans[i].second + 1 << endl;
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(50);
	//init();
	solve();

	//cout << "finish" << endl;
	//stop
	return 0;
}