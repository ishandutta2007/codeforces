#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 3e5 + 5;

int n;
char s[MAXN];
int a[MAXN], res[MAXN];

int fa[MAXN], siz[MAXN];
inline void init(int n){ for(int i=0; i<=n; ++i) fa[i] = i, siz[i] = 1;}
int find(int u){ return fa[u] == u? u: fa[u] = find(fa[u]);}
inline void connect(int u,int v)
{
	u = find(u); v = find(v);
	if(u != v) siz[v] += siz[u], fa[u] = v;
}

void get_res(int beg)
{
	for(int i=1; i<=n; ++i) a[i] = (s[i] == 'R');
	for(int i=beg+1; i<=n; i+=2) a[i] ^= 1;
	
	init(n);
	for(int i=1; i<=n; ++i) if(!a[i])
		connect(i-1,i);
	
	for(int i=beg; i<=n; i+=2) res[i] = siz[find(i)];
}

void solve(void)
{
	scanf("%d%s",&n,s+1);
	
	get_res(0); get_res(1);
	for(int i=0; i<=n; ++i) printf("%d ",res[i]);
	putchar('\n');
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}