#include<bits/stdc++.h>
using namespace std;
const int maxn=500010;
int hea[maxn],nxt[maxn],to[maxn],w[maxn],q[maxn],dis[maxn][2],col[maxn],tot,h,e;
void add(int a,int b,int c) {
	nxt[++tot]=hea[a];
	hea[a]=tot;
	to[tot]=b;
	w[tot]=c;
}
int main() {
	memset(dis,-1,sizeof(dis));
	memset(col,-1,sizeof(col));
	int n,m,a,b,c;
	scanf("%d%d",&n,&m);
	dis[n][0]=dis[n][1]=0;
	for(int i=1;i<=m;i++) {
		scanf("%d%d%d",&a,&b,&c);
		add(b,a,c);
	}
	q[h=e=1]=n;
	dis[n][0]=dis[n][1]=col[n]=0;
	while(h<=e) {
		int x=q[h++];
		for(int i=hea[x];i;i=nxt[i]) {
			if(~dis[to[i]][w[i]])continue;
			if(!~dis[to[i]][w[i]]) {
				dis[to[i]][w[i]]=max(dis[x][0],dis[x][1])+1;
				if(!~col[to[i]])col[to[i]]=w[i]^1;
			}
			if(~dis[to[i]][w[i]^1])q[++e]=to[i];
		}
	}
	if(!~dis[1][0]||!~dis[1][1])puts("-1");
	else printf("%d\n",max(dis[1][0],dis[1][1]));
	for(int i=1;i<=n;i++)
		if(!~col[i])col[i]=0;
	for(int i=1;i<=n;i++)
		putchar(col[i]^48);
	puts("");
	return 0;
}