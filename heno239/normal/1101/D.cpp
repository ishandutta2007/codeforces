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
const ll mod = 998244353;
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
int gcd(int a, int b) {
	if (a < b)swap(a, b);
	while (b) {
		int r = a % b; a = b; b = r;
	}
	return a;
}
int a[1 << 18];
vector<int> G[1 << 18];

struct edge { int fr, to; };
vector<edge> e[1 << 18];

bool isp[1 << 18];
vector<int> p;
void init() {
	fill(isp + 2, isp + 200001, true);
	Rep(i, 2, 200001) {
		if (!isp[i])continue;
		p.push_back(i);
		for (int j = 2 * i; j < 200001; j += i) {
			isp[j] = false;
		}
	}
}
struct uf {
private:
	vector<int> par, ran,sum;
public:
	void init(int n) {
		par.resize(n);
		ran.resize(n);
		sum.resize(n);
		rep(i, n) {
			par[i] = i;
			ran[i] = 0;
			sum[i] = 1;
		}
	}
	int find(int x) {
		if (par[x] == x)return x;
		else return par[x]=find(par[x]);
	}
	int unite(int x, int y) {
		x = find(x); y = find(y);
		if (ran[x] < ran[y]) {
			par[x] = y; sum[y] += sum[x]; 
			return sum[y];
		}
		else {
			par[y] = x; sum[x] += sum[y];
			if (ran[x] == ran[y])ran[x]++;
			return sum[x];
		}
	}
	void subinit(int x) {
		par[x] = x; ran[x] = 0; sum[x] = 1;
	}
};
bool use[1 << 18];
bool used[1 << 18];
int ans;
int dfs(int id) {
	used[id] = true;
	int ma[2] = { 0,0 };
	rep(j, G[id].size()) {
		int to = G[id][j];
		if (used[to]||!use[to])continue;
		int val = dfs(to);
		if (val > ma[0]) {
			ma[1] = ma[0]; ma[0] = val;
		}
		else if (val > ma[1]) {
			ma[1] = val;
		}
	}
	ans = max(ans, ma[0] + ma[1] + 1);
	return ma[0] + 1;
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	init();
	int n; cin >> n;
	rep(i, n) {
		cin >> a[i];
	}
	rep(i, n - 1) {
		int u, v; cin >> u >> v; u--; v--;
		G[u].push_back(v); G[v].push_back(u);
		int cost = gcd(a[u], a[v]);
		int ori = cost;
		vector<int> z;
		rep(j, p.size()) {
			if (cost%p[j] == 0) {
				z.push_back(p[j]);
				while (cost%p[j] == 0)cost /= p[j];
			}
			else if (p[j] * p[j] > ori)break;
		}
		if (cost > 1)z.push_back(cost);
		sort(z.begin(), z.end());
		int len = unique(z.begin(), z.end()) - z.begin();
		rep(j, len) {
			e[z[j]].push_back({ u,v });
		}
		//cout << u << " " << v <<" "<<len << endl;
	}
	rep(i, n) {
		if (a[i] > 1)ans = 1;
	}
	rep(i, p.size()) {
		vector<int> z;
		rep(j, e[p[i]].size()) {
			if (!use[e[p[i]][j].fr]) {
				z.push_back(e[p[i]][j].fr);
			}
			if (!use[e[p[i]][j].to]) {
				z.push_back(e[p[i]][j].to);
			}
			use[e[p[i]][j].fr] = use[e[p[i]][j].to] = true;
		}
		rep(j, z.size()) {
			if (!used[z[j]])dfs(z[j]);
		}
		rep(j, z.size()) {
			used[z[j]] = false;
			use[z[j]] = false;
		}
	}
	cout << ans << endl;
	//stop
	return 0;
}