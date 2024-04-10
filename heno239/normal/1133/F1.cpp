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
typedef long double ld;
const ld INF = (ld)10000000000000;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef complex<ld> Point;
const ld eps = 1e-8;
const ld pi = acos(-1.0);
typedef pair<ld, ld> LDP;
typedef pair<ll, ll> LP;

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
vector<int> G[1 << 18];

vector<P> v;
vector<P> vl;
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	uf u; u.init(n);
	rep(i, m) {
		int a, b; cin >> a >> b; a--; b--;
		vl.push_back({ a,b });
		G[a].push_back(b); G[b].push_back(a);
	}
	int chk = -1; int ma = -1;
	rep(i, n) {
		if (ma < (int)G[i].size()) {
			chk = i; ma = G[i].size();
		}
	}
	rep(i, G[chk].size()) {
		int to = G[chk][i];
		if (u.same(chk, to))continue;
		v.push_back({ chk+1,to+1 });
		u.unite(to, chk);
	}
	rep(i, m) {
		int l = vl[i].first, r = vl[i].second;
		if (u.same(l, r))continue;
		v.push_back({ l + 1,r + 1 });
		u.unite(l, r);
	}
	rep(i, n - 1) {
		cout << v[i].first << " " << v[i].second << endl;
	}
	//stop
		return 0;
}