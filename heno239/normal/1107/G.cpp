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
int n; ll a;
ll d[1 << 19], c[1 << 19];

ll le[1 << 19], ri[1 << 19],mid[1<<19];
ll ans = 0;
struct uf {
private:
	vector<int> par, ran;
public:
	uf(int n) {
		par.resize(n);
		ran.resize(n);
		rep(i, n) {
			par[i] = i;
			ran[i] = 0;
		}
	}
	int find(int x) {
		if(par[x] == x)return x;
		else return par[x] = find(par[x]);
	}
	void unite(int x, int y,ll cost) {
		x = find(x), y = find(y);
		if (x == y)return;
		ans = max(ans, ri[x] + le[y] - cost * cost);
		if (ran[x] < ran[y]) {
			par[x] = y;
			le[y] = max(le[x], mid[x] + le[y]);
			ri[y] = max(ri[y], mid[y] + ri[x]);
			mid[y] += mid[x];
		}
		else {
			par[y] = x;
			if (ran[x] == ran[y])ran[x]++;
			le[x] = max(le[x], mid[x] + le[y]);
			ri[x] = max(ri[y], mid[y] + ri[x]);
			mid[x] += mid[y];
		}

	}
	bool same(int x, int y) {
		return find(x) == find(y);
	}
};
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	vector<LP> v;
	cin >> n >> a;
	uf u(n);
	rep(i, n) {
		cin >> d[i] >> c[i];
	}
	rep(i, n - 1) {
		v.push_back({ d[i + 1] - d[i], i });
	}
	sort(v.begin(), v.end());
	rep(i, n) {
		ans = max(ans, a - c[i]);
		mid[i] = a - c[i];
		le[i] = a - c[i];
		ri[i] = a - c[i];
	}
	rep(i, n - 1) {
		int id = v[i].second;
		ll cost = v[i].first;
		u.unite(id, id + 1,cost);
		int p = u.find(id);
		//cout << le[p] << " " << ri[p] << endl;
		ans = max({ ans,le[p] - cost * cost,ri[p] - cost * cost });
		//cout << ans << endl;
	}
	cout << ans << endl;
	//stop
	return 0;
}