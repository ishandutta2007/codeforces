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
#include<numeric>
using namespace std;

//#define int long long
typedef long long ll;

typedef unsigned long long ul;
typedef unsigned int ui;
constexpr ll mod = 1000000007;
const ll INF = mod * mod;
typedef pair<int, int>P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
#define all(v) (v).begin(),(v).end()
typedef pair<ll, ll> LP;
typedef long double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-12;
const ld pi = acos(-1.0);

struct BIT {
private:
	vector<int> node; int n;
public:

	void init(int n_) {
		n = n_; node.resize(n, 0);
	}
	//0-indexed
	void add(int a, int w) {
		for (int i = a; i < n; i |= i + 1)node[i] += w;
	}
	//[0,a)
	int sum(int a) {
		int ret = 0;
		for (int i = a - 1; i >= 0; i = (i&(i + 1)) - 1)ret += node[i];
		return ret;
	}
	//[a,b)
	int sum(int a, int b) {
		return sum(b) - sum(a);
	}
};

struct edge {
	int to, id;
};
vector<edge> G[1 << 17];
void solve() {
	int n; cin >> n;
	rep(i, n - 1) {
		int a, b; cin >> a >> b; a--; b--;
		G[a].push_back({ b,i });
		G[b].push_back({ a,i });
	}
	vector<int> loc(n - 1);
	vector<vector<int>> vs;
	int root = 0;
	rep(i,n) {
		if (G[i].size() >= 3)root = i;
	}
	for (edge e : G[root]) {
		int cur = e.to;
		int pre = root;
		loc[e.id] = e.to;
		vector<int> ids;
		while (true) {
			ids.push_back(cur);
			if (G[cur].size() == 1)break;
			if (G[cur][0].to != pre) {
				loc[G[cur][0].id] = G[cur][0].to;
				pre = cur;
				cur = G[cur][0].to;
			}
			else {
				loc[G[cur][1].id] = G[cur][1].to;
				pre = cur;
				cur = G[cur][1].to;
			}
		}
		vs.push_back(ids);
	}
	vector<P> trans(n);
	int sz = vs.size();
	rep(i, sz)rep(j, vs[i].size()) {
		trans[vs[i][j]] = { i,j };
	}
	vector<BIT> vb(sz);
	rep(i, sz) {
		vb[i].init(vs[i].size());
	}
	int q; cin >> q;
	rep(aa, q) {
		int t; cin >> t;
		if (t == 1) {
			int c; cin >> c; c--;
			P p = trans[loc[c]];
			vb[p.first].add(p.second, -1);
		}
		else if (t == 2) {
			int c; cin >> c; c--;
			P p = trans[loc[c]];
			vb[p.first].add(p.second, 1);
			//cout << "?! " << p.first << " " << p.second << "\n";
		}
		else {
			int a, b; cin >> a >> b; a--; b--;
			
			if (a == b) {
				cout << 0 << "\n"; continue;

			}
			P pa = trans[a];
			P pb = trans[b];
			if (a == root) {
				//cout << "?? " << pb.first << " " << pb.second  << "\n";
				if (vb[pb.first].sum(0, pb.second + 1)==0) {
					cout << pb.second + 1 << "\n";
				}
				else {
					cout << -1 << "\n";
				}
			}
			else if (b == root) {
				if (vb[pa.first].sum(0, pa.second + 1) == 0) {
					cout << pa.second + 1 << "\n";
				}
				else {
					cout << -1 << "\n";
				}
			}
			else {
				if (pa.first == pb.first) {
					int le = min(pa.second, pb.second);
					int ri = max(pa.second, pb.second);
					if (vb[pa.first].sum(le + 1, ri + 1) == 0) {
						cout << ri - le << "\n";
					}
					else {
						cout << -1 << "\n";
					}
				}
				else {
					bool valid = true;
					if (vb[pa.first].sum(0, pa.second + 1) > 0)valid = false;
					if (vb[pb.first].sum(0, pb.second + 1) > 0)valid = false;
					if (valid) {
						cout << pa.second + pb.second + 2 << "\n";
					}
					else {
						cout << -1 << "\n";
					}
				}
			}
		}
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(7);
	//init_f();
	//init();

	solve();
	stop
		return 0;
}