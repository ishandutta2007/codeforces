#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int hea[N],cur[N],to[6*N],nxt[6*N],deg[N],f[3*N],sk[3*N],top,tot,M;
void add(int a,int b) {
	deg[a]++;
	nxt[++tot]=hea[a];
	hea[a]=tot;
	to[tot]=b;
}
void dfs(int x) {
	for(int &i=cur[x];i;i=nxt[i]) {
		if(f[i/2])continue;
		f[i/2]=1;
		int y=to[i];
		dfs(y);
		sk[++top]=y;
	}
}
int main() {
	int n,m,x,y;
	scanf("%d%d",&n,&m);
	tot=1;
	for(int i=1;i<=m;i++) {
		scanf("%d%d",&x,&y);
		add(x,y),add(y,x);
	}
	int las=0;
	for(int i=1;i<=n;i++)
		if(deg[i]&1) {
			if(las)add(las,i),add(i,las),las=0;
			else las=i;
		}
	if(tot/2%2)add(1,1),add(1,1);
	memcpy(cur,hea,sizeof(cur));
	printf("%d\n",tot/2);
	for(int i=1;i<=n;i++) {
		top=0;
		dfs(i);
		sk[++top]=i;
		for(int i=top,c=0;i>1;i--,c^=1) {
			if(c)printf("%d %d\n",sk[i],sk[i-1]);
			else printf("%d %d\n",sk[i-1],sk[i]);
		}
	}
	return 0;
}