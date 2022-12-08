#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=100010;
int hea[maxn],nxt[maxn<<1],to[maxn<<1],f[maxn],c[maxn],d[maxn],ans[maxn],tot=1,sum,s;
void add(int a,int b) {
	nxt[++tot]=hea[a];
	hea[a]=tot;
	to[tot]=b;
}
void dfs(int x,int fa) {
	c[x]=1;
	for(int i=hea[x];i;i=nxt[i]) {
		if(to[i]==fa)continue;
		if(!c[to[i]]) {
			d[to[i]]=d[x]+1;
			dfs(to[i],x);
		} else if(d[to[i]]<d[x]) {
			sum+=!((d[to[i]]-d[x])&1);
			f[x]+=(d[to[i]]-d[x])&1?-1:1;
			f[to[i]]+=(d[to[i]]-d[x])&1?1:-1;
		}
	}
}
void updata(int x,int fa) {
	c[x]=0;
	for(int i=hea[x];i;i=nxt[i]) {
		if(to[i]==fa)continue;
		if(c[to[i]]) {
			updata(to[i],x);
			if(f[to[i]]==sum)ans[++s]=i>>1;
			f[x]+=f[to[i]];
		} else if(d[to[i]]<d[x]&&sum==1&&!((d[to[i]]-d[x])&1))ans[++s]=i>>1;
	}
}
int main() {
	int n,m,a,b;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++) {
		scanf("%d%d",&a,&b);
		add(a,b);
		add(b,a);
	}
	for(int i=1;i<=n;i++)
		if(!c[i])dfs(i,0);
	cerr<<sum<<endl;
	if(!sum) {
		printf("%d\n",m);
		for(int i=1;i<=m;i++)printf("%d ",i);
		return 0;
	}
	for(int i=1;i<=n;i++)
		if(c[i])updata(i,0);
	printf("%d\n",s);
	sort(ans+1,ans+s+1);
	for(int i=1;i<=s;i++)printf("%d ",ans[i]);
	return 0;
}