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
priority_queue<int> q[1<<17];
int c[1 << 17];
queue<int> que;
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n, m; cin >> n >> m;
	rep(i, n) {
		int s, r; cin >> s >> r; s--;
		q[s].push(r);
	}
	int ans = 0;
	rep(i, m) {
		if(!q[i].empty())que.push(i);
	}
	int sum = 0;
	while (!que.empty()) {
		int sum = 0;
		int len = que.size();
		rep(aa, len) {
			int i = que.front(); que.pop();
			bool use = true;
			c[i] += q[i].top(); q[i].pop();
			if (c[i] > 0) {
				sum += c[i];
			}
			else use = false;
			if (!q[i].empty()&&use)que.push(i);
		}
		ans = max(ans, sum);
	}
	cout << ans << endl;
	return 0;
}