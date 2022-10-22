#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void rd(int &x)
{
	int f=1;
	x=0;
	char c=getchar();
	while(c<'0' || c>'9')
	{
		if(c=='-')	f=-1;
		c=getchar();;
	}
	while(c>='0' && c<='9')	x=x*10+c-'0',c=getchar();
	x*=f;
}
int n, m, a[200005], b[200005], fa[200005], p[200005], q[200005], t, v[200005];
ll s[200005], c[3];
vector<int> e[200005];

int findSet(int x) {
	if(x==fa[x])	return x;
	return fa[x]=findSet(fa[x]);
}

inline bool dfs(int x, int k) {
	v[x] = k, c[k] += s[x];
	bool ok = 1;
	for (unsigned int  i = 0; i < e[x].size(); i++) {
		int y = e[x][i];
		if (v[y] == v[x]) ok = 0;
		if (!v[y] && !dfs(y, 3 - k)) ok = 0;
	}
	return ok;
}

inline bool solve() {
	rd(n), rd(m), t = 0;
	for(int i=1;i<=n;++i)	scanf("%d",&a[i]);
	for(int i=1;i<=n;++i)	scanf("%d",&b[i]);
	for (int i = 1; i <= n; i++) fa[i] = i, s[i] = v[i] = 0, e[i].clear();
	for (int i = 1,  x, y; i <= m; i++) {
		rd(x), rd(y);
		p[++t] = x, q[t] = y;
	}
	for (int i = 1; i <= n; i++) s[findSet(i)] += b[i] - a[i];
	for (int i = 1; i <= t; i++) {
		int x = findSet(p[i]), y = findSet(q[i]);
		e[x].push_back(y), e[y].push_back(x);
	}
	for (int i = 1; i <= n; i++)
		if (findSet(i) == i && !v[i]) {
			c[1] = c[2] = 0;
			bool ok = dfs(i, 1);
			if (ok && c[1] != c[2]) return 0;
			if (!ok && ((c[1] ^ c[2]) & 1)) return 0;
		}
	return 1;
}

int main() {
	int T;
	rd(T);
	while (T--) puts(solve() ? "YES" : "NO");
	return 0;
}