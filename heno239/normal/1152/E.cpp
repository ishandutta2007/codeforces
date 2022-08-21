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
typedef unsigned long long ul;
typedef unsigned int ui;
const ll mod = 1000000007;
typedef double ld;
typedef complex<ld> Point;
const ll INF = mod*mod;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
const ld eps = 1e-8;
const ld pi = acos(-1.0);
typedef pair<ld, ld> LDP;
typedef pair<ll, ll> LP;
#define fr first
#define sc second

struct uf {
private:
	vector<int> par, ran;
public:
	void init(int n) {
		par.resize(n, 0);
		ran.resize(n, 0);
		rep(i, n) {
			par[i] = i;
		}
	}
	int find(int x) {
		if (par[x] == x)return x;
		else return par[x] = find(par[x]);
	}
	void unite(int x, int y) {
		x = find(x), y = find(y);
		if (x == y)return;
		if (ran[x] < ran[y]) {
			par[x] = y;
		}
		else {
			par[y] = x;
			if (ran[x] == ran[y])ran[x]++;
		}
	}
	bool same(int x, int y) {
		return find(x) == find(y);
	}
};

int c[1 << 18];
multiset<int> G[1 << 18];
void solve() {
	int n;
	cin >> n;
	vector<int> a(n - 1), b(n - 1);
	vector<int> v;
	rep(i, n - 1) {
		cin >> a[i]; v.push_back(a[i]);
	}
	rep(i, n - 1) {
		cin >> b[i]; v.push_back(b[i]);
	}
	rep(i, n - 1) {
		if (a[i] > b[i]) {
			cout << -1 << endl; return;
		}
	}
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	map<int, int> mp;
	rep(i, v.size())mp[v[i]] = i;
	uf u; u.init(v.size());
	rep(i, n - 1) {
		int x = mp[a[i]],y=mp[b[i]];
		c[x]++; c[y]++; u.unite(x, y);
		G[x].insert(y); G[y].insert(x);
	}
	rep(i, v.size()) {
		if (!u.same(0, i)) {
			cout << -1 << endl; return;
		}
	}
	vector<int> cnt;
	rep(i, v.size()) {
		if (c[i] % 2)cnt.push_back(i);
	}
	vector<int> ans;
	if (cnt.size() != 0 && cnt.size() != 2) {
		cout << -1 << endl; return;
	}
	if (cnt.size() == 0) {
		int to = *G[0].begin(); 
		G[0].erase(G[0].begin());
		G[to].erase(G[to].find(0));
		ans.push_back(v[0]);
		cnt = { 0,to };
	}
	int s = cnt[0], g = cnt[1];
	//cout << v[s] << " " << v[g] << endl;
	int cur = s;
	stack<int> q; q.push(s);
	while (cur != g) {
		int to = *G[cur].begin(); 
		G[cur].erase(G[cur].begin());
		G[to].erase(G[to].find(cur));
		cur = to; q.push(cur);
	}
	while (!q.empty()) {
		int z = q.top();
		if (G[z].size()) {
			int to = *G[z].begin();
			G[z].erase(G[z].begin());
			G[to].erase(G[to].find(z));
			cur = to; q.push(cur);
			while (cur != z) {
				to = *G[cur].begin();
				G[cur].erase(G[cur].begin());
				G[to].erase(G[to].find(cur));
				cur = to;q.push(cur);
			}
		}
		else {
			ans.push_back(v[z]);
			q.pop();
		}
	}
	rep(i, ans.size()) {
		if (i > 0)cout << " ";
		cout << ans[i];
	}
	cout << endl;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
	//stop
		return 0;
}