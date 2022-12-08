#include<bits/stdc++.h>
using namespace std;
const int N=3e5+10;
vector<int>S[N],T[N];
#define add(S,x,y) S[x].push_back(y),S[y].push_back(x)
int jp[N][20],dep[N],dfn[N],low[N],in[N],dfns,cnt;
int v[N],a[N],b[N],rt[N],h[N*3],F[N],Dfn[N],sk[N];
map<int,map<int,int> >f;
void tarjan(int x,int fa) {
	dfn[x]=low[x]=++dfns;
	for(int y:T[x]) {
		if(y==fa) {
			fa=0;
			continue;
		}
		if(!dfn[y]) {
			tarjan(y,x);
			if(low[y]>dfn[x])
				f[x][y]=f[y][x]=1;
			low[x]=min(low[x],low[y]);
		} else low[x]=min(low[x],dfn[y]);
	}
}
void color(int x) {
	in[x]=cnt;
	for(int y:T[x]) {
		if(f[x][y]||in[y])continue;
		color(y);
	}
}
void dfs(int x,int fa,int RT) {
	rt[x]=RT;
	dep[x]=dep[fa]+1;
	Dfn[x]=++dfns;
	jp[x][0]=fa;
	for(int i=1;i<20;i++)
		jp[x][i]=jp[jp[x][i-1]][i-1];
	for(int y:S[x])
		if(!rt[y])dfs(y,x,RT);
}
void calc(int x) {
	F[x]=1;
	for(int y:T[x])
		if(!f[x][y]&&!F[y])
			calc(y);
}
int cmp(int a,int b) {
	return Dfn[a]<Dfn[b];
}
int lca(int a,int b) {
	if(dep[a]<dep[b])swap(a,b);
	for(int i=19;i>=0;i--)
		if(dep[jp[a][i]]>=dep[b])
			a=jp[a][i];
	if(a==b)return a;
	for(int i=19;i>=0;i--)
		if(jp[a][i]!=jp[b][i]) {
			a=jp[a][i];
			b=jp[b][i];
		}
	return jp[a][0];
}
void build(int n) {
	sort(h+1,h+n+1,cmp);
	int top=0;
	for(int i=1;i<=n;i++) {
		if(h[i]==h[i-1])continue;
		if(top&&rt[h[i]]!=rt[sk[top]]) {
			while(--top)add(T,sk[top],sk[top+1]);
			T[sk[top=1]=h[i]].clear();
			F[h[i]]=dfn[h[i]]=low[h[i]]=0;
			continue;
		}
		int p=lca(sk[top],h[i]),las=0;
		while(dep[p]<dep[sk[top]]) {
			if(las)add(T,sk[top],las);
			las=sk[top--];
		}
		if(p!=sk[top]) {
			T[sk[++top]=p].clear();
			F[p]=dfn[p]=low[p]=0;
		}
		if(las)add(T,p,las);
		T[sk[++top]=h[i]].clear();
		F[h[i]]=dfn[h[i]]=low[h[i]]=0;
	}
	while(--top)add(T,sk[top],sk[top+1]);
}
int R,n;
int rotate(int element) {
	element=(element+R)%n;
	if (element==0) {
		element=n;
	}
	return element;
}
int main() {
	int n,m,q,x,y;
	scanf("%d%d%d",&n,&m,&q);
	::n=n;
	for(int i=1;i<=m;i++) {
		scanf("%d%d",&x,&y);
		add(T,x,y);
	}
	for(int i=1;i<=n;i++)
		if(!dfn[i])tarjan(i,0);
	for(int i=1;i<=n;i++)
		if(!in[i])cnt++,color(i);
	f.clear();
	for(int i=1;i<=n;i++) {
		for(int j:T[i])
			if(in[i]!=in[j]&&!f[in[i]][in[j]]) {
				f[in[i]][in[j]]=1;
				S[in[i]].push_back(in[j]);
			}
	}
	n=cnt;
	dfns=0;
	for(int i=1;i<=n;i++)
		if(!rt[i])dfs(i,0,i);
	int k1,k2;
	for(int I=1;I<=q;I++) {
		scanf("%d%d",&k1,&k2);
		for(int i=1;i<=k1;i++) {
			scanf("%d",v+i);
			v[i]=rotate(v[i]);
			h[i]=v[i]=in[v[i]];
		}
		int m=k1;
		for(int i=1;i<=k2;i++) {
			scanf("%d%d",a+i,b+i);
			a[i]=rotate(a[i]);
			b[i]=rotate(b[i]);
			h[++m]=a[i]=in[a[i]];
			h[++m]=b[i]=in[b[i]];
		}
		build(m);
		for(int i=1;i<=k2;i++)
			add(T,a[i],b[i]);
		f.clear();
		for(int i=1;i<=m;i++)
			if(!dfn[h[i]])
				tarjan(h[i],0);
		calc(v[1]);
		int fl=1;
		for(int i=1;i<=k1;i++)
			if(!F[v[i]])fl=0;
		puts(fl?"YES":"NO");
		R=(R+fl*I)% ::n;
	}
	return 0;
}