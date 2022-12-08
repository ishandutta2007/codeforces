#include<bits/stdc++.h>
using namespace std;
const int N=3e5+10;
int hea[N],to[N<<1],nxt[N<<1],d[N],f[N],in[N],tot=1;
void add(int a,int b) {
	nxt[++tot]=hea[a];
	hea[a]=tot;
	to[tot]=b;
}
int dfs(int x) {
	in[x]=1;
	int c=0;
	for(int i=hea[x];i;i=nxt[i]) {
		int y=to[i];
		if(in[y])continue;
		c^=f[i/2]=dfs(y);
	}
	return c^d[x];
}
int main() {
	int n,m,a,b,cc=0;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) {
		scanf("%d",d+i);
		if(d[i]==1)cc++;
	}
	for(int i=1;i<=m;i++) {
		scanf("%d%d",&a,&b);
		add(a,b),add(b,a);
	}
	for(int i=1;i<=n;i++)
		if(d[i]==-1) {
			if(cc&1)d[i]=1,cc++;
			else d[i]=0;
		}
	if(cc&1)return puts("-1"),0;
	dfs(1);
	int cnt=0;
	for(int i=1;i<=m;i++)
		cnt+=f[i];
	printf("%d\n",cnt);
	for(int i=1;i<=m;i++)
		if(f[i])printf("%d\n",i);
	return 0;
}