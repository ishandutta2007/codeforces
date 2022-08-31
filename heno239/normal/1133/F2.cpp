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
bool used[1 << 18];

vector<P> ans;

vector<vector<int>> b;

vector<int> v;
void sea(int id) {
	used[id] = true;
	rep(j, G[id].size()) {
		int to = G[id][j];
		if (to == 0) {
			v.push_back(id);
		}
		if (used[to])continue;
		sea(to);
	}
}
vector<LP> vl;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	used[0] = 1;
	int n, m,d;
	cin >> n >> m>>d;
	uf u; u.init(n);
	rep(i, m) {
		int a, b; cin >> a >> b; a--; b--;
		G[a].push_back(b); G[b].push_back(a);
		if (a != 0 && b != 0)vl.push_back({ a,b });
	}
	rep(i, G[0].size()) {
		int to = G[0][i];
		if (used[to])continue;
		v.clear();
		sea(to);
		b.push_back(v);
	}
	int mi = b.size();
	int ma = 0;
	rep(i, b.size()) {
		ma += b[i].size();
	}
	//cout << mi << endl;
	if (d < mi || ma < d) {
		cout << "NO" << endl;
	}
	else {
		cout << "YES" << endl;
		int len = b.size();
		rep(i, b.size()) {
			int saiaku = len - 1 - i;
			int le = 0;
			while (le<b[i].size() && d>saiaku) {
				d--;
				ans.push_back({ 0,b[i][le] });
				u.unite(0, b[i][le]);
				le++;
			}
		}
		rep(i, vl.size()) {
			int l = vl[i].first, r = vl[i].second;
			if (u.same(l, r))continue;
			ans.push_back({ l,r });
			u.unite(l, r);
		}
		//cout << ans.size() << endl;
		rep(i, n - 1) {
			cout << ans[i].first+1 << " " << ans[i].second+1 << endl;
		}
	}
	//stop
		return 0;
}