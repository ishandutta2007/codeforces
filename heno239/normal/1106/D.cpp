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
#include<utility>
using namespace std;
typedef long long ll;
typedef unsigned int ui;
const ll mod = 1000000007;
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
const ld eps = 1e-11;
const ld pi = acos(-1.0);
typedef pair<ll, ll> LP;
typedef pair<ld, ld> LDP;
typedef unsigned long long ul;
int n, m;
bool used[1 << 17];
vector<int> G[1 << 17];
priority_queue<int, vector<int>, greater<int>> q;
vector<int> ans;
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n >> m;
	rep(i, m) {
		int a, b; cin >> a >> b; a--; b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	used[0] = true; ans.push_back(0);
	rep(i, G[0].size()) {
		int to = G[0][i];
		if (!used[to]) {
			used[to] = true;
			q.push(to);
		}
	}
	while (!q.empty()) {
		int id = q.top(); q.pop();
		ans.push_back(id);
		rep(j, G[id].size()) {
			int to = G[id][j];
			if (used[to])continue;
			used[to] = true;
			q.push(to);
		}
	}
	rep(i, n) {
		if (i > 0)cout << " ";
		cout << ans[i]+1;
	}
	cout << endl;
	//stop
	return 0;
}