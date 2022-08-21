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

vector<int> loc[1 << 19];

//dif,num
vector<LP> memo[1 << 19];

LP memmo[1 << 19];
void solve() {
	int n; cin >> n;
	vector<P> v(n);
	vector<int> x;
	int ma = -1;
	rep(i, n) {
		cin >> v[i].second >> v[i].first;
		x.push_back(v[i].first);
		x.push_back(v[i].second);
	}
	sort(v.begin(), v.end());
	sort(x.begin(), x.end());
	x.erase(unique(x.begin(), x.end()), x.end());
	map<int, int> mp;
	rep(i, x.size())mp[x[i]] = i;
	rep(i, n) {
		v[i].first = mp[v[i].first];
		v[i].second = mp[v[i].second];
		loc[v[i].first].push_back(v[i].second);
		ma = max(ma, v[i].first);
	}
	int las = 0; int sum = x[0]; ll num = 1;
	ll ans = 0;
	rep(i, x.size()) {
		//cout << x[i] << " hello " << endl;
		int ad = x[i] - x[las];
		rep(j, memo[i].size()) {
			LP &p = memo[i][j];
			//cout << p.first << " " << p.second << endl;
			if (sum + ad > p.first) {
				las = i; sum = p.first; num = p.second;
				ad = 0;
			}
			else if (sum + ad == p.first) {
				num += p.second;
				if (num >= mod)num -= mod;
			}
		}
		rep(j, loc[i].size()) {
			int to = loc[i][j];
			memo[to].push_back({ sum+ad,num });
		}
		memmo[i] = { sum + ad,num };
		//cout << x[i] << " " << las << " " << sum << " " << num << endl;
	}
	rep(i, x.size()) {
		if (i > ma&&memmo[i].first == sum) {
			ans += memmo[i].second;
			if (ans >= mod)ans -= mod;
		}
	}
	cout << ans << endl;
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