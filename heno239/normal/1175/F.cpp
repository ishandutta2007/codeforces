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
#include<cassert>
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
typedef vector<int> vec;
typedef vector<string> svec;

struct SegT {
private:
	int sz; vector<int> node;
	const int init_c = 1;
public:
	SegT(int n) {
		sz = 1;
		while (sz < n)sz *= 2;
		node.resize(2 * sz - 1, init_c);
		per(i, sz - 1) {
			node[i] = f(node[2 * i + 1], node[2 * i + 2]);
		}
	}
	int f(int a, int b) {
		return a+b;
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
		if (r <= a || b <= l)return 0;
		else if (a <= l && r <= b)return node[k];
		else {
			int vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
			int vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
			return f(vl, vr);
		}
	}
};
const int mn = 300001;
vector<int> loc[mn];
vector<int> u[mn];

int rri[mn];
void solve() {
	int n; cin >> n;
	vector<int> a(n);
	rep(i, n) {
		cin >> a[i];
		loc[a[i]].push_back(i);
	}
	rep1(i, n) {
		rep(j, (int)loc[i].size()-1) {
			int l = loc[i][j], r = loc[i][j + 1];
			u[r - l+1].push_back(l);
		}
	}
	ll ans = 0;
	queue<int> ban;
	vector<bool> used(n, false);
	SegT st(n);
	set<int> ss;
	rep(i, n)ss.insert(i);
	ss.insert(-1); ss.insert(n);
	rep1(i, n) {
		int len = ban.size();
		rep(j, len) {
			int cur = ban.front(); ban.pop();
			if (!used[cur]) {
				used[cur] = true;
				st.update(cur, 0);
				if (cur - 1 >= 0 && !used[cur - 1])ban.push(cur-1);
			}
		}
		rep(j, u[i].size()) {
			if (!used[u[i][j]]) {
				int cur = u[i][j];
				used[cur] = true;
				st.update(cur, 0);
				if (cur - 1 >= 0 && !used[cur - 1])ban.push(cur-1);
			}
		}
		rep(j, loc[i].size()) {
			int id = loc[i][j];
			ss.erase(id);
		}
		map<int, bool> mp;
		rep(j, loc[i].size()) {
			int id = loc[i][j];
			ss.insert(id);
			auto itr = ss.find(id);
			itr--; int le = *itr; itr++; itr++; int ri = *itr;
			ss.erase(id);
			le = le + 1;
			ri = ri - i;
			//cout << id << " " << le << " " << ri <<" "<<st.query(le,ri+1)<< endl;
			if (mp[le])continue;
			mp[le] = true;
			ans += st.query(le, ri + 1);
		}
		//cout << ans << endl;
	}
	cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(5);
	//while (cin >> n>>h>>m>>s,n)solve();
	solve();
	//stop
	return 0;
}