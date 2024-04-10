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
const ll INF = mod * mod;
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

struct SegT {
private:
	int sz; vector<int> node;
	const int init_c = mod;
public:
	void init(int n) {
		sz = 1;
		while (sz < n)sz *= 2;
		node.resize(2 * sz - 1, init_c);
	}
	void init(vector<int> v) {
		int n = v.size();
		sz = 1;
		while (sz < n)sz *= 2;
		node.resize(2 * sz - 1, init_c);
		rep(i, n) {
			node[i + sz - 1] = v[i];
		}
		per(i, sz - 1) {
			node[i] = min(node[i * 2 + 1], node[i * 2 + 2]);
		}
	}
	int f(int a, int b) {
		return min(a, b);
	}
	void update(int k, int a) {
		k += sz - 1;
		node[k] = a;
		while (k > 0) {
			k = (k - 1) / 2;
			node[k] = f(node[k * 2 + 1], node[k * 2 + 2]);
		}
	}
	int query(int a, int b, int k = 0, int l = 0, int r = -1) {
		if (r < 0)r = sz;
		if (r <= a || b <= l)return init_c;
		else if (a <= l && r <= b)return node[k];
		else {
			int vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
			int vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
			return f(vl, vr);
		}
	}
};
//len
vector<P> le[1 << 18], ri[1 << 18];
SegT stle[1 << 18], stri[1 << 18];
vector<int> lex[1 << 18], rix[1 << 18];
void solve() {
	int n, x; cin >> n >> x;
	rep(i, n) {
		int l, r; cin >> l >> r;
		int len = r - l + 1;
		int c; cin >> c;
		le[len].push_back({ l,c });
		ri[len].push_back({ r,c });
	}
	rep(i, (1 << 18)) {
		if (le[i].size() > 0) {
			rep(j, le[i].size()) {
				lex[i].push_back(le[i][j].first);
			}
			sort(lex[i].begin(), lex[i].end());
			lex[i].erase(unique(lex[i].begin(), lex[i].end()), lex[i].end());
			vector<int> v(lex[i].size(),mod);
			rep(j, le[i].size()) {
				int id = lower_bound(lex[i].begin(), lex[i].end(), le[i][j].first) - lex[i].begin();
				v[id] = min(v[id], le[i][j].second);
			}
			stle[i].init(v);
		}
		if (ri[i].size() > 0) {
			rep(j, ri[i].size()) {
				rix[i].push_back(ri[i][j].first);
			}
			sort(rix[i].begin(), rix[i].end());
			rix[i].erase(unique(rix[i].begin(), rix[i].end()), rix[i].end());
			vector<int> v(rix[i].size(), mod);
			rep(j, ri[i].size()) {
				int id = lower_bound(rix[i].begin(), rix[i].end(), ri[i][j].first) - rix[i].begin();
				v[id] = min(v[id], ri[i][j].second);
			}
			stri[i].init(v);
		}
	}
	int ans = 2 * mod;
	rep(i, (1 << 18)) {
		if (i > x)break;
		rep(j, le[i].size()) {
			int l = le[i][j].first, cost = le[i][j].second;
			int r = l + i - 1;
			int idle = upper_bound(lex[x-i].begin(), lex[x-i].end(), r) - lex[x-i].begin();
			int idri = lower_bound(rix[x - i].begin(), rix[x - i].end(), l) - rix[x - i].begin();
			int cle = stle[x-i].query(idle, lex[x-i].size());
			if(cle!=mod)ans = min(ans, cle + cost);
			int cri = stri[x - i].query(0, idri);
			if(cri!=mod)ans = min(ans, cri + cost);

			//cout << cle + cost << " " << cri + cost << " " << i << endl;
		}
	}
	if (ans == 2 * mod)ans = -1;
	cout << ans << endl;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
	//stop
	return 0;
}