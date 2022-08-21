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
int col[1 << 19];
vector<int> s[1 << 19];
int l[1 << 19];
vector<int> G[1 << 19];
bool used[1 << 19];
int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n, m; cin >> n >> m;
	rep(i, n) {
		cin >> l[i];
		rep(j, l[i]) {
			int c; cin >> c; s[i].push_back(c);
		}
		sort(s[i].begin(), s[i].end());
	}
	rep(i, n - 1) {
		int u, v; cin >> u >> v; u--; v--;
		G[u].push_back(v); G[v].push_back(u);
	}
	queue<int> q;
	q.push(0); used[0] = true;
	while (!q.empty()) {
		int id = q.front(); q.pop();
		vector<int> v;
		rep(i, l[id]) {
			int c = s[id][i];
			if (col[c]) {
				v.push_back(col[c]);
			}
		}
		sort(v.begin(), v.end());
		int now = 1;
		int len = v.size();
		int ri = 0;
		rep(i, l[id]) {
			while (ri < len&&v[ri] == now) {
				now++; ri++;
			}
			int c = s[id][i];
			if (!col[c]) {
				col[c] = now; now++;
			}
		}
		rep(j, (int)G[id].size()) {
			int to = G[id][j];
			if (used[to])continue;
			used[to] = true; q.push(to);
		}
	}
	int out = 0;
	rep1(i, m) {
		if (!col[i])col[i] = 1;
		out = max(out, col[i]);
	}
	cout << out << endl;
	rep1(i, m) {
		if (i > 1)cout << " ";
		cout << col[i];
	}
	cout << endl;
	//stop
	return 0;
}