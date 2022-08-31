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
using namespace std;
typedef long long ll;
typedef unsigned int ui;
const ll mod = (ll)(1e+9) + 7;
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
const ld eps = 1e-8;
const ld pi = acos(-1.0);
typedef pair<ll, ll> LP;
typedef pair<ld, ld> LDP;

int par[200000];
int rank1[200000];
void init(int n) {
	for (int i = 0; i < n; i++) {
		par[i] = i;
		rank1[i] = 0;
	}
}
int find(int x) {
	if (par[x] == x) {
		return x;
	}
	else {
		return par[x] = find(par[x]);
	}
}
void unite(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y)return;
	if (rank1[x] < rank1[y]) {
		par[x] = y;
	}
	else {
		par[y] = x;
		if (rank1[x] == rank1[y])rank1[x]++;
	}
}
bool same(int x, int y) {
	return find(x) == find(y);
}
int n, m;
typedef pair<ll, P> speP;
priority_queue<speP, vector<speP>, greater<speP>> q;
priority_queue<LP, vector<LP>, greater<LP>> que;
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n >> m; init(n);
	rep(i, n) {
		ll v; cin >> v;
		que.push({ v,i });
	}
	rep(i, m) {
		int a, b; ll c; cin >> a >> b >> c; a--; b--;
		q.push({ c,{a,b} });
	}
	ll ans = 0;
	rep(i, n-1) {
		while (!q.empty()) {
			speP t = q.top();
			if (same(t.second.first, t.second.second))q.pop();
			else break;
		}
		while (!que.empty()) {
			LP x = que.top(); que.pop(); LP y = que.top(); que.pop();
			if (same(x.second, y.second)) {
				que.push(x);
			}
			else {
				que.push(x); que.push(y); break;
			}
		}
		if (q.empty()) {
			LP x = que.top(); que.pop(); LP y = que.top(); que.pop();
			ans += x.first + y.first; que.push(x);
			unite(x.second, y.second);
		}
		else {
			LP x = que.top(); que.pop(); LP y = que.top(); que.pop();
			speP z = q.top();
			if (z.first < x.first + y.first) {
				que.push(x); que.push(y);
				ans += z.first;
				unite(z.second.first, z.second.second);
			}
			else {
				que.push(x); q.push(z);
				ans += x.first + y.first;
				unite(x.second, y.second);
			}
		}
	}
	cout << ans << endl;
	return 0;
}