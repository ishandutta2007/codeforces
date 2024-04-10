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

typedef long long  ll;

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

vector<int> G[1 << 18];
vector<int> T[1 << 18];
int par[1 << 18];
void rem(int id, int fr) {
	rep(j, G[id].size()) {
		int to = G[id][j];
		if (to == fr)continue;
		rem(to, id);
		par[to] = id; T[id].push_back(to);
	}
}
int depth[1 << 18];
void calc_depth(int id, int k) {
	depth[id] = k;
	rep(i, T[id].size()) {
		int to = T[id][i];
		calc_depth(to, k + 1);
	}
}
int dx;
int sz[1 << 18];
int calc_size(int id) {
	int ret = 0;
	if (depth[id] == dx)ret++;
	rep(j, T[id].size()) {
		int to = T[id][j];
		ret += calc_size(to);
	}
	return sz[id]=ret;
}
bool ban[1 << 18];
void solve() {
	int n; cin >> n;
	rep(i, n - 1) {
		int a, b; cin >> a >> b; a--; b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	cout << "d 1" << endl;
	cin >> dx;
	rem(0, -1); calc_depth(0, 0); calc_size(0);
	if (dx == 0) {
		cout << "! " << 1 << endl; return;
	}
	int root = 0;
	int cur = 0, dcur = 0;
	while (true) {
		if (dcur == dx) {
			cout << "d " << cur+1 << endl;
			int dist; cin >> dist;
			int bac = dcur + dx - dist; bac /= 2;
			if (dist == 0) {
				cout << "! " << cur+1 << endl; return;
			}
			while (dcur != bac) {
				ban[cur] = true;
				dcur--;
				cur = par[cur];
			}
			root = cur;
			continue;
		}
		vector<P> v;
		rep(j, T[cur].size()) {
			int to = T[cur][j];
			if (ban[to])continue;
			v.push_back({ sz[to],to });
		}
		sort(v.begin(), v.end());
		int sum = 0;
		rep(i, v.size()) {
			sum += v[i].first;
		}
		if (sum - v.back().first >= v.back().first) {
			if(root == cur) {
				cout << "s " << cur + 1 << endl;
				int nex; cin >> nex; nex--;
				root = nex, cur = nex; dcur++;
				if (dcur == dx) {
					cout << "! " << cur + 1 << endl; return;
				}
				continue;
			}
			else {
				cout << "d " << cur + 1 << endl;
				int dist; cin >> dist;
				int bac = dcur + dx - dist; bac /= 2;
				if (dist == 0) {
					cout << "! " << cur + 1 << endl; return;
				}
				while (dcur != bac) {
					ban[cur] = true;
					dcur--;
					cur = par[cur];
				}
				root = cur;
				continue;
			}
		}
		else {
			cur = v.back().second; dcur++;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(5);
	//while (cin >> w>>h>>n,n)solve();
	solve();
	//stop
	return 0;
}