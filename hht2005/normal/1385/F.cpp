#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+10;
int siz[maxn],deg[maxn],hea[maxn],to[maxn],nxt[maxn],q[maxn],f[maxn],tot;
void add(int a,int b) {
	nxt[++tot]=hea[a];
	hea[a]=tot;
	to[tot]=b;
	deg[a]++;
}
int main() {
	int T;
	scanf("%d",&T);
	while(T--) {
		int n,k,a,b,h=1,e=0;
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++)
			hea[i]=siz[i]=deg[i]=f[i]=0;
		tot=0;
		for(int i=1;i<n;i++) {
			scanf("%d%d",&a,&b);
			add(a,b);
			add(b,a);
		}
		if(k==1) {
			printf("%d\n",n-1);
			continue;
		}
		for(int i=1;i<=n;i++) {
			if(deg[i]>1)continue;
			f[i]=1;
			for(int j=hea[i];j;j=nxt[j])siz[to[j]]++;
		}
		int ans=0;
		for(int i=1;i<=n;i++)
			if(siz[i]>0&&siz[i]%k==0&&deg[i]-siz[i]==1)f[q[++e]=i]=1;
		while(h<=e) {
			int x=q[h++];
			for(int i=hea[x];i;i=nxt[i])
				if(!f[to[i]]) {
					siz[to[i]]++;
					if(siz[to[i]]%k==0&&deg[to[i]]-siz[to[i]]==1)f[q[++e]=to[i]]=1;
				}
		}
		for(int i=1;i<=n;i++)
			ans+=siz[i]/k;
		printf("%d\n",ans);
	}
	return 0;
}