#include<vector>
#include<set>
#include<map>
#include<queue>
#include<string>
#include<algorithm>
#include<iostream>
#include<bitset>
#include<functional>
#include<numeric>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cassert>
#include<cmath>
#include<ctime>
#include<complex>
using namespace std;
typedef long long LL;
typedef complex<double> Complex;
#define fi first
#define se second
#define ins insert
#define pb push_back
inline char GET_CHAR(){
	const int maxn = 131072;
	static char buf[maxn],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,maxn,stdin),p1==p2)?EOF:*p1++;
}
inline int getInt() {
	int res(0);
	char c = getchar();
	while(c < '0') c = getchar();
	while(c >= '0') {
		res = res * 10 + (c - '0');
		c = getchar();
	}
	return res;
}

inline int fastpo(int x, int n, int mod) {
	int res(1);
	while(n) {
		if(n & 1) {
			res = res * (LL)x % mod;
		}
		x = x * (LL) x % mod;
		n /= 2;
	}
	return res;
}
const int N = 300033;
const int LOG = 20;
const int mod = 1e9 + 7;
const int inf = 1e9 + 7;
int n, m;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int c[N][2], vst[N], dep[N], fa[N];
vector<int> e[N];
int main() {
	int n;
	scanf("%d", &n);
	for(int i(0); i < n - 1; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		e[x].pb(y);
		e[y].pb(x);
	}
	vector<int> q;
	q.push_back(1);
	vst[1] = 1;
	dep[1] = 0;
	for(int op(0); op < (int)q.size(); op++) {
		int v(q[op]);
		for(int y : e[v]) {
			if(!vst[y]) {
				vst[y] = 1;
				fa[y] = v;
				q.push_back(y);
				dep[y] = dep[v] + 1;
			}
		}
	}
	for(int i(n - 1); i >= 0; i--) {
		int v = q[i];
		c[v][dep[v] & 1]++;
		c[fa[v]][0] += c[v][0];
		c[fa[v]][1] += c[v][1];
	}
	LL ans = 0, ans1 = 0;
	for(int i(2); i <= n; i++) {
		int y = fa[i];
		ans += (LL)(c[i][0] + c[i][1]) * (n - c[i][0] - c[i][1]);
	}
	ans1 = c[1][1] * (LL)c[1][0];
	//cout << ans << ' ' << ans1 << endl;
	assert(ans % 2 == ans1 % 2);
	cout << (ans + ans1) / 2 << endl;
}