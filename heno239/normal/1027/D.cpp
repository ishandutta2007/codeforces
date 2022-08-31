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
using namespace std;
typedef long long ll;
typedef unsigned int ui;
const ll MOD = (1e+9) + 7;
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
const ld eps = 1e-11;
const ld pi = acos(-1.0);
typedef pair<ll, ll> LP;
typedef pair<ld, ld> LDP;
int c[200000], a[200000]; int n;
vector<int> G[200000];
int used[200000] = {};
int subused[200000] = {};
int main() {
	scanf("%d", &n);
	rep(i, n) {
		scanf("%d", &c[i]);
	}
	rep(i, n) {
		scanf("%d", &a[i]); a[i]--;
		G[a[i]].push_back(i);
	}
	ll out = 0;
	rep(i, n) {
		if (used[i])continue;
		int now = i;
		while (!subused[now]) {
			subused[now] = 1;
			now = a[now];
		}
		int chk = now; ll mi = c[chk]; now = a[now];
		while (now != chk) {
			mi = min(mi, (ll)c[now]); now = a[now];
		}
		out += mi;
		queue<int> q; q.push(chk);
		used[chk] = 1;
		while (!q.empty()) {
			int x = q.front();q.pop();
			int len = G[x].size();
			rep(j, len) {
				int v = G[x][j];
				if (used[v])continue;
				q.push(v); used[v] = 1;
			}
		}
	}
	printf("%lld", out);
	return 0;
}