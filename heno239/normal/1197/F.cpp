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
using namespace std;

//#define int long long
typedef long long ll;

typedef unsigned long long ul;
typedef unsigned int ui;
const ll mod = 998244353;
const ll INF = mod * mod;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef pair<ll, ll> LP;
typedef vector<ll> vec;
typedef vector<string> svec;
typedef long double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-8;

typedef long long Data;
typedef vector<Data> Array;
typedef vector<Array> mat;

vec operator*(const mat &A, const vec &b) {
	vec ret(b.size());
	rep(i, b.size()) {
		rep(j, b.size()) {
			ret[i] = (ret[i] + A[i][j] * b[j])%mod;
		}
	}
	return ret;
}
mat operator*(const mat &lhs, const mat &rhs) {
	mat ret(lhs.size(), Array(rhs[0].size(), 0));
	rep(i, lhs.size())rep(j, rhs[0].size())rep(k, rhs.size()) {
		ret[i][j] = (lhs[i][k]*rhs[k][j]+ret[i][j])%mod;
	}
	return ret;
}
mat scalar(int sz, Data k) {
	mat ret(sz, Array(sz, 0));
	rep(i, sz)ret[i][i] = k;
	return ret;
}
mat base;

mat AA[32];
vec mtpow(vec v,int n) {
	rep(i, 31) {
		if (n&(1 << i)) {
			v = AA[i] * v;
		}
	}
	return v;
}

int ident(vector<int> v) {
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	rep(i, v.size()) {
		if (i != v[i])return i;
	}
	return v.size();
}

typedef pair<vector<int>, ll> speP;

vector<P> memo[1000];

vector<int> to[64];



void solve() {
	int n; cin >> n;
	vector<ll> a(n);
	rep(i, n) {
		cin >> a[i];
	}
	int m; cin >> m;
	
	rep(i, m) {
		int x, y, c;
		cin >> x >> y >> c;
		x--; y--; c--;
		memo[x].push_back({ y,c });
	}
	int f[3][3];
	rep(i, 3) {
		rep(j, 3) {
			cin >> f[i][j];
		}
	}
	mat colall(64), col1(64), col2(64), col3(64);
	rep(i, 64) {
		colall[i].resize(64);
		col1[i].resize(64);
		col2[i].resize(64);
		col3[i].resize(64);
	}
	//
	rep(i, 64) {
		vector<int> pre;
		int cop = i;
		rep(j, 3) {
			pre.push_back(cop % 4); cop /= 4;
		}
		vector<int> g;
		int nexid;
		int nex;
		//1
		g.clear();
		rep(j, 3) {
			if (f[0][j]) {
				g.push_back(pre[j]);
			}
		}
		nexid = ident(g);
		nex = nexid; nex += pre[0] * 4; nex += pre[1] * 16;
		col1[nex][i]++;
		colall[nex][i]++;
		to[i].push_back(nex);

		//2
		g.clear();
		rep(j, 3) {
			if (f[1][j]) {
				g.push_back(pre[j]);
			}
		}
		nexid = ident(g);
		nex = nexid; nex += pre[0] * 4; nex += pre[1] * 16;
		col2[nex][i]++;
		colall[nex][i]++;
		to[i].push_back(nex);

		//3
		g.clear();
		rep(j, 3) {
			if (f[2][j]) {
				g.push_back(pre[j]);
			}
		}
		nexid = ident(g);
		nex = nexid; nex += pre[0] * 4; nex += pre[1] * 16;
		col3[nex][i]++;
		colall[nex][i]++;
		to[i].push_back(nex);
	}
	queue<int> que;

	vector<bool> used(64, false);
	used[63] = true;
	que.push(63);
	while (!que.empty()) {
		int id = que.front(); que.pop();
		rep(j, to[id].size()) {
			int tid = to[id][j];
			if (used[tid])continue;
			used[tid] = true;
			que.push(tid);
		}
	}
	vector<int> exiid;
	rep(i, 64) {
		if (used[i])exiid.push_back(i);
	}
	int len = exiid.size();
	//cout << exiid.size() << endl;
	base = scalar(len, 1);
	mat alt(exiid.size());
	rep(i, len) {
		alt[i].resize(len);
		rep(j, len) {
			alt[i][j] = colall[exiid[i]][exiid[j]];
		}
	}
	colall = alt;
	rep(i, len) {
		rep(j, len) {
			alt[i][j] = col1[exiid[i]][exiid[j]];
		}
	}
	col1 = alt;
	rep(i, len) {
		rep(j, len) {
			alt[i][j] = col2[exiid[i]][exiid[j]];
		}
	}
	col2 = alt;
	rep(i, len) {
		rep(j, len) {
			alt[i][j] = col3[exiid[i]][exiid[j]];
		}
	}
	col3 = alt;

	AA[0] = colall;
	rep(i, 31) {
		AA[i + 1] = AA[i] * AA[i];
	}

	vector<ll> dp(4, 0),cop(4,0);
	dp[0] = 1;

	rep(i, n) {
		rep(j, 4) {
			cop[j] = 0;
		}
		vec v(len, 0);
		v[len-1] = 1;
		sort(memo[i].begin(), memo[i].end());
		int cur = 0;
		rep(j, memo[i].size()) {
			int dif = memo[i][j].first - cur;
			cur = memo[i][j].first;
			v = mtpow(v,dif);
			if (memo[i][j].second == 0) {
				v = col1 * v;
			}
			else if (memo[i][j].second == 1) {
				v = col2 * v;
			}
			else {
				v = col3 * v;
			}
			cur++;
		}
		int dif = a[i] - cur;
		v = mtpow(v,dif);
		rep(j, len) {
			rep(k, 4) {
				int nk = k ^ (exiid[j] % 4);
				(cop[nk] += dp[k] * v[j])%=mod;
			}
		}
		rep(j, 4) {
			dp[j] = cop[j];
		}
	}
	cout << dp[0] << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//init();
	solve();
	//cout << "finish" << endl;
	//stop
	return 0;
}