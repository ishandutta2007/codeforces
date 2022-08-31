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

int n,k;
vector<int> G[1 << 18];
vector<int> dist;
int hantai(int s) {
	dist.clear();
	dist.resize(n, mod);
	dist[s] = 0;
	queue<int> q;
	q.push(s);
	int res;
	while (!q.empty()) {
		int id = q.front(); q.pop();
		rep(j, G[id].size()) {
			int to = G[id][j];
			if (dist[id] + 1 < dist[to]) {
				dist[to] = dist[id] + 1;
				q.push(to);
				//cout << "?? " << s << " " << to << endl;
			}
		}
		res = id;
	}
	return res;
}

int depth(int id, int fr) {
	int res = 0;
	rep(j, G[id].size()) {
		int to = G[id][j];
		if (to == fr)continue;
		res = max(res, depth(to, id));
	}
	return res + 1;
}

vector<int> ans(n);

void tocol(int id, int fr, int col, bool inc) {
	if (inc)col++;
	else col--;
	col = (col%k + k) % k;
	//cout << "????" << col << endl;
	ans[id] = col;
	rep(j, G[id].size()) {
		int to = G[id][j];
		if (to == fr)continue;
		tocol(to, id, col, inc);
	}
}

void solve() {
	cin >> n >> k;
	ans.resize(n);
	rep(i, n - 1) {
		int a, b; cin >> a >> b; a--; b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	if (k == 2) {
		cout << "Yes" << endl;
		queue<int> q;
		q.push(0);
		vector<bool> used(n, false); used[0] = true;
		while (!q.empty()) {
			int id = q.front(); q.pop();
			rep(j, G[id].size()) {
				int to = G[id][j];
				if (used[to])continue;
				ans[to] = ans[id] ^ 1;
				used[to] = true;
				q.push(to);
			}
		}
		rep(i, n) {
			if (i > 0)cout << " ";
			cout << ans[i] + 1;
		}
		cout << endl;
		return;
	}
	int l = hantai(0);
	int r = hantai(l);
	int ma = dist[r];
	//cout << ma << endl;
	vector<int> ldist = dist;
	hantai(r);
	vector<int> &rdist = dist;
	int cur = l;
	vector<int> pathes;
	vector<bool> inpathes(n, false);
	//cout << "? " << l << " " << r << endl;
	while (cur != r) {
		inpathes[cur] = true;
		pathes.push_back(cur);
		rep(j, G[cur].size()) {
			int to = G[cur][j];
			if (inpathes[to])continue;
			if (ma == ldist[to] + rdist[to]) {
				cur = to; break;
			}
		}
	}
	inpathes[r] = true;
	pathes.push_back(r);
	if (pathes.size() < k) {
		//cout << pathes.size() << endl;
		cout << "Yes" << endl;
		rep(i, n) {
			if (i > 0)cout << " ";
			cout << (i%k)+1;
		}
		cout << endl;
		return;
	}
	rep(i, pathes.size()) {
		int col = i % k;
		int id = pathes[i];
		ans[id] = col;
		int dl = ldist[id], dr = rdist[id];
		int mal = 0;
		vector<int> szs;
		rep(j, G[id].size()) {
			int to = G[id][j];
			if (inpathes[to])continue;
			int sz = depth(to, id);
			szs.push_back(sz);
		}
		sort(szs.begin(), szs.end(),greater<int>());
		if (szs.size() >= 2) {
			if (szs[0] + szs[1] + 1 >= k) {
				cout << "No" << endl; return;
			}
		}
		rep(j, G[id].size()) {
			int to = G[id][j];
			if (inpathes[to])continue;
			int sz = depth(to, id);
			if (sz + dl+1 >= k && sz + dr+1 >= k) {
				cout << "No" << endl; return;
			}
			if (sz + dl+1 >= k) {
				tocol(to, id, i%k, true);
			}
			else {
				tocol(to, id, i%k, false);
			}
		}
	}
	cout << "Yes" << endl;
	rep(i, n) {
		if (i > 0)cout << " ";
		cout << ans[i] + 1;
	}
	cout << endl;
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