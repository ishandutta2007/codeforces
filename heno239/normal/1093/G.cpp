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
const ld eps = 1e-2;
const ld pi = acos(-1.0);
typedef pair<ll, ll> LP;

struct SegT {
private:
	int sz; vector<int> node;
	const int init_c = -mod;
public:
	void init(int n) {
		sz = 1;
		while (sz < n)sz *= 2;
		node.resize(2 * sz - 1, init_c);
	}
	int f(int a, int b) {
		return max(a, b);
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

int x[1 << 18][5];
int main() {
	int n, k; scanf(" %d %d", &n, &k);
	SegT s[32];
	int u = (1 << k) - 1;
	rep(i, 1 << k) {
		s[i].init(n);
	}
	rep(i, n) {
		rep(j, k) {
			scanf(" %d", &x[i][j]);
			//cin >> x[i][j];
		}
		rep(j, (1 << k)) {
			int sum = 0;
			rep(l, k) {
				if (j&(1 << l))sum += x[i][l];
				else sum -= x[i][l];
			}
			//cout <<  j << " " << sum << endl;
			s[j].update(i,sum);
		}
	}
	int q; cin >> q;
	rep(aa, q) {
		int t; scanf(" %d", &t);
		if (t == 1) {
			int i; cin >> i; i--;
			rep(j, k)scanf(" %d", &x[i][j]);
			rep(j, (1 << k)) {
				int sum = 0;
				rep(l, k) {
					if (j&(1 << l))sum += x[i][l];
					else sum -= x[i][l];
				}
				s[j].update(i,sum);
			}
		}
		else {
			int ma = -mod;
			int l, r; scanf(" %d %d", &l, &r); l--;
			rep(j, (1 << (k))) {
				ma = max(ma, s[j].query(l, r) + s[u - j].query(l, r));
				//cout << j << " " << s[j].query(l, r) << endl;
			}
			printf("%d\n", ma);
			//cout << ma << endl;
		}
	}
	//stop
	return 0;
}