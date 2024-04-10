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
const ld eps = 1e-9;
const ld pi = acos(-1.0);
typedef pair<ll, ll> LP;
struct uf {
private:
	vector<int> par, ran;
public:
	uf(int n) {
		par.resize(n);
		ran.resize(n);
		rep(i, n) {
			par[i] = i, ran[i] = 0;
		}
	}
	int find(int x) {
		if (par[x] == x) {
			return x;
		}
		else return par[x] = find(par[x]);
	}
	void unite(int x, int y) {
		x = find(x);
		y = find(y);
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
struct edge {
	int u, v; ll c;
	bool operator<(const edge &e)const {
		if (e.c != c)return c < e.c;
		if (e.u != u)return e.u < u;
		return e.v < v;
	}
};
edge e[1 << 18];
bool used[1 << 18];
int n, m;
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n >> m;
	uf u(n);
	rep(i, m) {
		int a, b; cin >> a >> b; ll w; cin >> w; a--; b--;
		e[i] = { a,b,w };
	}
	sort(e, e + m);
	int cnt = 0;
	rep(i, m) {
		int le = i;
		while (i + 1 < m&&e[i].c == e[i + 1].c) {
			i++;
		}
		Rep1(j, le, i) {
			if (u.same(e[j].u, e[j].v)) {
				used[j] = true;
			}
		}
		Rep1(j, le, i) {
			if (used[j])continue;
			if (!u.same(e[j].u, e[j].v)) {
				u.unite(e[j].u, e[j].v);
			}
			else {
				cnt++;
			}
		}
	}
	cout << cnt << endl;
	//stop
	return 0;
}