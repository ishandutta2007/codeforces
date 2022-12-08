#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
int hea[maxn*2],nxt[maxn*4],to[maxn*4],f[maxn*2],a[maxn],b[maxn],p1[maxn],p2[maxn],tot,c1,c2,n;
void add(int a,int b) {
	nxt[++tot]=hea[a];
	hea[a]=tot;
	to[tot]=b;
}
void dfs(int x,int v) {
	f[x]=v;
	if(x>n)c1++;
	else c2++;
	for(int i=hea[x];i;i=nxt[i])
		if(!f[to[i]])dfs(to[i],v);
}
void clear(int n) {
	tot=0;
	for(int i=1;i<=n;i++)p1[i]=p2[i]=0;
	for(int i=1;i<=2*n;i++)hea[i]=f[i]=0;
}
int main() {
	int T;
	scanf("%d",&T);
	while(T--) {
		int FL=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++) {
			scanf("%d",a+i);
			if(p1[a[i]]) {
				if(p2[a[i]])FL=1;
				p2[a[i]]=i;
			} else p1[a[i]]=i;
		}
		for(int i=1;i<=n;i++) {
			scanf("%d",b+i);
			if(p1[b[i]]) {
				if(p2[b[i]])FL=1;
				p2[b[i]]=i;
			} else p1[b[i]]=i;
		}
		if(FL) {
			clear(n);
			puts("-1");
			continue;
		}
		for(int i=1;i<=n;i++) {
			if(p1[i]==p2[i])continue;
			if((a[p1[i]]==i)==(a[p2[i]]==i)) {
				add(p1[i],p2[i]+n);
				add(p2[i]+n,p1[i]);
				add(p2[i],p1[i]+n);
				add(p1[i]+n,p2[i]);
			} else {
				add(p1[i],p2[i]);
				add(p2[i],p1[i]);
				add(p1[i]+n,p2[i]+n);
				add(p2[i]+n,p1[i]+n);
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++)
			if(!f[i]&&!f[i+n]) {
				c1=c2=0;
				dfs(i,1);
				if(c1>c2) {
					c1=c2=0;
					dfs(i+n,2);
				}
				ans+=c1;
			}
		printf("%d\n",ans);
		for(int i=1;i<=n;i++)
			if(f[n+i]==2||(f[n+i]==1&&f[i]==0))
				printf("%d ",i);
		puts("");
		clear(n);
	}
	return 0;
}