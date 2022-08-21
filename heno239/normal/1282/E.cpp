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
const ll mod = 998244353;
const ll INF = mod * mod;
typedef pair<int, int>P;
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
const ld eps = 1e-6;
const ld pi = acos(-1.0);
typedef vector<vector<ll>> mat;
typedef vector<ll> vec;

void solve() {
	int n; cin >> n;
	vector<int> cnt(n);
	vector<vector<int>> v(n-2);
	rep(i, n - 2)v[i].resize(3);
	vector<vector<int>> loc(n);
	vector<bool> used(n - 2, false);
	rep(i, n - 2) {
		int a, b, c; cin >> a >> b >> c; a--; b--; c--;
		cnt[a]++; cnt[b]++; cnt[c]++;
		v[i] = { a,b,c };
		loc[a].push_back(i);
		loc[b].push_back(i);
		loc[c].push_back(i);
	}
	queue<int> q;
	vector<int> ansp(n), ansq(n - 2);
	rep(i, n) {
		if (cnt[i] == 1)q.push(i);
	}
	vector<P> mv;
	vector<int> rid;
	rep(i, n - 3) {
		int x = q.front(); q.pop();
		rid.push_back(x);
		int chk;
		rep(j, loc[x].size()) {
			int id = loc[x][j];
			if (used[id])continue;
			chk = id;
		}
		int id = chk; used[id] = true;
		//cout << id << " " << x << endl;
		ansq[i] = id;
		int a[3];
		rep(j, 3)a[j] = v[id][j];
		rep(j, 3) {
			//cout << a[j] << endl;
			cnt[a[j]]--;
			if (cnt[a[j]] == 1) {
				//cout << a[j] << endl;
				q.push(a[j]);
			}
		}
		vector<int> ds;
		rep(j, 3) {
			if (a[j] != x)ds.push_back(a[j]);
		}
		mv.push_back({ ds[0],ds[1] });
	}
	//rep(i, n)cout << i << " " << cnt[i] << endl;
	rep(i, n - 2)if (!used[i])ansq[n - 3] = i;
	rid.push_back(q.front());
	vector<set<int>> st(n);
	int le, ri;
	vector<int> stas;
	rep(i, 3) {
		int x = q.front(); q.pop();
		stas.push_back(x);
	}
	rep(i, 3)rep(j, 3)if (i != j)st[stas[i]].insert(stas[j]);
	rep(i, n - 3) {
		int mid = rid[n - 4 - i];
		int l = mv[n - 4 - i].first, r = mv[n - 4 - i].second;
		//cout << mid+1 << " " << l+1 << " " << r+1 << endl;
		st[l].erase(r);
		st[r].erase(l);
		st[l].insert(mid);
		st[r].insert(mid);
		st[mid].insert(l);
		st[mid].insert(r);
	}
	int cur = 0; int fr = -1;
	ansp[0] = 0;
	rep1(i, n - 1) {
		for (auto&& to : st[cur]) {
			if (fr == to)continue;
			fr = cur;
			ansp[i] = to;
			cur = to;
			break;
		}
	}
	rep(i, n) {
		if (i > 0)cout << " ";
		cout << ansp[i] + 1;
	}
	cout << endl;
	rep(i, n - 2) {
		if (i > 0)cout << " ";
		cout << ansq[i] + 1;
	}
	cout << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(8);
	//init();
	int t; cin >> t;
	rep(i, t) {
		solve();
	}
	//stop
	return 0;
}