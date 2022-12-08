#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
int t[maxn],a[maxn],b[maxn],hea[maxn],nxt[maxn<<1],to[maxn<<1],deg[maxn],q[maxn],p[maxn],tot,h,e;
void add(int a,int b) {
	deg[b]++;
	nxt[++tot]=hea[a];
	hea[a]=tot;
	to[tot]=b;
}
int main() {
	int T;
	scanf("%d",&T);
	while(T--) {
		memset(hea,tot=0,sizeof(hea));
		memset(deg,0,sizeof(deg));
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=m;i++) {
			scanf("%d%d%d",t+i,a+i,b+i);
			if(t[i])add(a[i],b[i]);
		}
		h=1,e=0;
		for(int i=1;i<=n;i++)
			if(!deg[i])q[++e]=i;
		while(h<=e) {
			int x=q[h++];
			for(int i=hea[x];i;i=nxt[i]) {
				deg[to[i]]--;
				if(!deg[to[i]])
					q[++e]=to[i];
			}
		}
		if(e<n) {
			puts("NO");
			continue;
		}
		puts("YES");
		for(int i=1;i<=n;i++)p[q[i]]=i;
		for(int i=1;i<=m;i++) {
			if(t[i])printf("%d %d\n",a[i],b[i]);
			else if(p[a[i]]<p[b[i]])printf("%d %d\n",a[i],b[i]);
			else printf("%d %d\n",b[i],a[i]);
		}
	}
	return 0;
}