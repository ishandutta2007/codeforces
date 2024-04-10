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

int n;
int cnt = 0;
int par[300001];
int find(int id) {
	if (par[id] == id)return id;
	else return par[id] = find(par[id]);
}
int l[300001], r[300001];

bool f = true;
void dfs(int id) {
	if (l[id] < 0) {
		if (!f)cout << " ";
		else f = false;
		cout << id;
	}
	else {
		dfs(l[id]); dfs(r[id]);
	}
}
int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n; cnt = n+1;
	rep(i, 300001) {
		par[i] = i;
		l[i] = r[i] = -1;
	}
	rep(i, n - 1) {
		int u, v; cin >> u >> v;
		u = find(u), v = find(v);
		par[u] = cnt, par[v] = cnt;
		l[cnt] = u, r[cnt] = v; cnt++;
	}
	dfs(cnt - 1);
	cout << endl;
	//stop
	return 0;
}