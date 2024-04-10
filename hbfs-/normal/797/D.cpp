#include <bits/stdc++.h>
#define INF 2147483647
#define N 1000500
using namespace std;

int a[N],b[N],rt,n,l[N],r[N],ans;
map<int,int> vis;

inline int rd() {
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

void dfs(int u,int L,int R) {
	if (u==-1) return ;
	if (L<=a[u] && a[u]<=R) vis[ a[u] ] = 1;
	dfs(l[u], L, min(a[u],R));
	dfs(r[u], max(a[u],L), R);
}

int main() {
	n = rd();
	for (int i=1;i<=n;i++) {
		a[i] = rd(), l[i] = rd(), r[i] = rd();
		if (~l[i]) b[ l[i] ] = 1;
		if (~r[i]) b[ r[i] ] = 1;
	}
	
	
	for (int i=1;i<=n;i++) if (!b[i]) rt = i;
	dfs(rt,0,INF);
	for (int i=1;i<=n;i++) if (!vis[ a[i] ]) ans++;
	printf("%d\n",ans);
	return 0;
}