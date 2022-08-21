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
typedef pair<int, int>P;
typedef pair<int, bool> sP;
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
const ld eps = 1e-8;
const ld pi = acos(-1.0);
typedef vector<vector<ll>> mat;
typedef vector<ll> vec;


struct uf {
private:
	vector<int> par, ran;
public:
	uf(int n) {
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
vector<pair<int, int>> generate_tree(int sz) {
	vector<pair<int, int>> res;
	random_device rnd;
	mt19937 mt(rnd());
	uf u(sz);
	for (int i = 0; i < sz - 1; i++) {
		int a = 0, b = 0;
		while (u.same(a, b)) {
			a = mt() % sz; b = mt() % sz;
			if (a < 0)a += sz; if (b < 0)b += sz;
			if (!u.same(a, b))break;
		}
		u.unite(a, b);
		res.push_back({ a,b });
	}
	return res;
}
void output_tree(int sz) {
	vector<P> u = generate_tree(sz); 
	random_device rnd;
	mt19937 mt(rnd());
	rep(i, sz-1) {
		int z = mt(); z %= 26; if (z < 0)z += 26;
		char c = 'a' + z;
		cout << u[i].first << " " << u[i].second << " " << c << endl;
	}
}

struct Node {
	Node *ch[26];
	int cnt;

	Node() {
		rep(i, 26) {
			ch[i] = NULL;
			cnt = 0;
		}
	}
};

int merge(Node* le, Node* ri) {
	int res = 0;
	rep(i, 26) {
		if (ri->ch[i] != NULL && ri->ch[i]->cnt>0) {
			if (le->ch[i] == NULL) {
				le->ch[i] = new Node();
			}
			if (le->ch[i]->cnt == 0) {
				res++;
				//cout << char('a' + i) << endl;
			}
			le->ch[i]->cnt++;
			res += merge(le->ch[i], ri->ch[i]);
		}
	}
	return res;
}
void non_merge(Node* le, Node* ri) {
	rep(i, 26) {
		if (ri->ch[i] != NULL && ri->ch[i]->cnt>0) {
			le->ch[i]->cnt--;
			non_merge(le->ch[i], ri->ch[i]);
		}
	}
}
int n;
struct edge {
	int to; int id;
};
vector<edge> G[1 << 19];
int ans[1 << 19];

int subch[1 << 19];
int init(int id) {
	int res = 1;
	rep(j, G[id].size()) {
		int to = G[id][j].to;
		res += init(to);
	}
	return subch[id] = res;
}

int madepth;
int exicnt[1 << 19];
Node* dfs(int id, int depth) {
	exicnt[depth]++;
	if (G[id].size() == 0) {
		Node* res = new Node();
		return res;
	}
	madepth = max(madepth, depth);
	vector<Node*> er;
	vector<int> ids;
	int ma = -1; int chk = -1;
	rep(j, G[id].size()) {
		int to = G[id][j].to;
		if (ma < subch[to]) {
			ma = subch[to]; chk = j;
		}
	}
	int cnt = ma;
	//cout << id << " N " << cnt << endl;
	Node* res = dfs(G[id][chk].to, depth + 1);
	rep(j, G[id].size()) {
		if (j == chk)continue;
		int to = G[id][j].to;
		ids.push_back(G[id][j].id);
		Node* nex = dfs(to, depth + 1);
		//cout << "is " << id << endl;
		cnt += merge(res, nex);
		er.push_back(nex);
	}
	cnt--;
	//cout << "!! " << depth << " " << cnt << endl;
	ans[depth] += cnt;
	rep(j, er.size()) {
		non_merge(res, er[j]);
	}
	Node* nex = new Node();
	nex->ch[G[id][chk].id] = res;
	nex->ch[G[id][chk].id]->cnt++;
	rep(j, er.size()) {
		nex->ch[ids[j]] = er[j];
		nex->ch[ids[j]]->cnt++;
	}

	//cout << id << " " <<depth<<" "<< cnt << endl;
	return nex;
}

void solve() {
	cin >> n;
	rep(i, n - 1) {
		int a, b; cin >> a >> b; a--; b--; char c; cin >> c;
		G[a].push_back({ b,c - 'a' });
	}
	init(0);
	dfs(0, 0);
	rep(i, (1 << 19) - 1) {
		exicnt[i + 1] += exicnt[i];
		ans[i] += exicnt[i];
	}
	int mi = mod;
	int z = 0;
	rep(i, madepth + 1) {
		//cout << i << " " << ans[i] << endl;
		if (mi > ans[i]) {
			z = i + 1; mi = ans[i];
		}
	}
	/*int zz = exicnt[madepth + 1];
	if (n - zz < mi) {
	mi = n - zz; z = madepth;
	}*/
	cout << mi << endl;
	cout << z << endl;
}


signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(7);
	//init();
	//output_tree(10);
	solve();
	//stop
	return 0;
}