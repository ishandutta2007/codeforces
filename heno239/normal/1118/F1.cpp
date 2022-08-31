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
const ll mod = 1000000007;
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

const int mn = 300001;
int n;
int a[mn];
vector<int> G[mn];

bool used[mn];
int numr[mn], numb[mn];
int nr, nb;
int dfs(int id) {
	int res = 0;
	used[id] = true;
	if (a[id] == 1) {
		numr[id]++;
	}
	else if (a[id] == 2) {
		numb[id]++;
	}
	rep(j, G[id].size()) {
		int to = G[id][j];
		if (used[to])continue;
		res += dfs(to);
		//cout << id << " " << to << " " << numr[to] << " " << numb[to] << endl;
		if (nr == numr[to] && numb[to] == 0)res++;
		if (nb == numb[to] && numr[to] == 0)res++;
		numr[id] += numr[to];
		numb[id] += numb[to];
	}
	return res;
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n;
	rep(i, n) {
		cin >> a[i];
		if (a[i] == 1)nr++;
		else if (a[i] == 2)nb++;
	}
	rep(i, n - 1) {
		int u, v; cin >> u >> v; u--; v--;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	cout << dfs(0) << endl;
	//stop
	return 0;
}