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
#include<complex>
#include<bitset>
#include<stack>
#include<unordered_map>
using namespace std;
typedef long long ll;
typedef unsigned int ui;
const ll mod = (ll)(1e+9) + 7;
const ll INF = (ll)1000000007 * 1000000007;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef long double ld;
typedef complex<ld> Point;
const ld eps = 1e-8;
const ld pi = acos(-1.0);
typedef pair<ll, ll> LP;
typedef pair<ld, ld> LDP;
int n;
P info[1 << 18];
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n;
	if (n == 3) {
		cout << "1 2 3" << endl; return 0;
	}
	rep1(i, n) {
		int x, y; cin >> x >> y;
		info[i] = { x,y };
	}
	vector<int> ans;
	int cur = 1; ans.push_back(1);
	rep(i, n - 1) {
		int to1 = info[cur].first; int to2 = info[cur].second;
		if (to2 == info[to1].first || to2 == info[to1].second) {
			ans.push_back(to1); cur = to1;
		}
		else {
			ans.push_back(to2); cur = to2;
		}
	}
	rep(i, n) {
		if (i > 0)cout << " ";
		cout << ans[i];
	}
	cout << endl;
	return 0;
}