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

int n, q;
ll ans[1 << 20];

struct BIT {
private:
	vector<ll> node; int n;
public:
	BIT(int n_) {
		n = n_; node.resize(n,0);
	}
	//0-indexed
	void add(int a, ll w) {
		for (int i = a; i < n; i |= i + 1)node[i] += w;
	}
	//[0,a)
	ll sum(int a) {
		ll ret = 0;
		for (int i = a - 1; i >= 0; i = (i&(i + 1)) - 1)ret += node[i];
		return ret;
	}
	//[a,b)
	ll sum(int a, int b) {
		return sum(b) - sum(a);
	}
};
struct qq {
	int l, r, id;
	bool operator<(const qq &q)const {
		if (l != q.l)return l < q.l;
		if (r != q.r)return r < q.r;
		return id < q.id;
	}
};
void calc(vector<int> p, vector<qq> query) {
	sort(query.begin(), query.end());
	vector<vector<int>> G(n);
	priority_queue<P, vector<P>, greater<P>> que;
	BIT b1(n),b2(n);
	rep(i, n) {
		bool f = true;
		while (!que.empty()) {
			P x = que.top();
			if (p[i] < x.first) {
				G[x.second].push_back(i);
				que.push({ p[i],i });
				b1.add(i, i - x.second - 1);
				f = false;
				break;
			}
			else {
				que.pop();
			}
		}
		if (f) {
			que.push({ p[i],i });
			b1.add(i, i); b2.add(i, 1);
		}
	}
	int cur = 0;
	rep(i, n) {
		while (cur < q&&query[cur].l == i) {
			int le=query[cur].l,ri=query[cur].r,id = query[cur].id;
			ans[id] += b1.sum(le, ri + 1);
			ans[id] -= b2.sum(le, ri + 1)*i;
			cur++;
		}
		rep(j, G[i].size()) {
			int to = G[i][j];
			b1.add(to, i+1);
			b2.add(to, 1);
		}
	}
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n >> q;
	vector<int> p(n);
	vector<qq> query(q);
	rep(i, n) {
		cin >> p[i];
	}
	rep(i, q) {
		cin >> query[i].l; query[i].l--;
	}
	rep(i, q) {
		cin >> query[i].r; query[i].r--;
	}
	rep(i, q)query[i].id = i;
	calc(p, query);
	reverse(p.begin(), p.end());
	rep(i, q) {
		int l = query[i].l, r = query[i].r;
		query[i].l = n - 1 - r;
		query[i].r = n - 1 - l;
	}
	calc(p, query);
	rep(i, q) {
		ans[i]+=query[i].r - query[i].l + 1;
	}
	rep(i, q) {
		if (i > 0)cout << " ";
		cout << ans[i];
	}
	cout << endl;
	//stop
	return 0;
}