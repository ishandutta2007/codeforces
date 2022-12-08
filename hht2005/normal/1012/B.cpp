#include<bits/stdc++.h>
using namespace std;
const int maxn=4e5+10;
int hea[maxn],nxt[maxn],to[maxn],f[maxn],tot;
void add(int a,int b) {
	nxt[++tot]=hea[a];
	hea[a]=tot;
	to[tot]=b;
}
void dfs(int x) {
	f[x]=1;
	for(int i=hea[x];i;i=nxt[i])
		if(!f[to[i]])dfs(to[i]);
}
int main() {
	int n,m,q,x,y,cnt=-1;
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=q;i++) {
		scanf("%d%d",&x,&y);
		add(x,y+n);
		add(y+n,x);
	}
	for(int i=1;i<=n+m;i++)
		if(!f[i])cnt++,dfs(i);
	printf("%d\n",cnt);
	return 0;
}