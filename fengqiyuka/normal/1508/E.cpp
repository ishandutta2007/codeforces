#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=3e5+100;
int a[N];bool bk[N];
vector<int> B[N];

int fa[N],dep[N],ID[N],son[N];
void dfs(int x){
	bk[x]=false;
	for(auto y:B[x]){
		if(bk[y]){
			fa[y]=x;
			dep[y]=dep[x]+1;
			dfs(y);
			son[x]++;
		}
	}
}

int si[N],p[N];
void dfs2(int x){
	for(auto y:B[x])
		if(fa[y]==x){
			dfs2(y);
			si[x]+=si[y];
		}
	if(p[x]==0) p[x]=a[x]-si[x];
}

bool cmp(int n1,int n2) {return (p[n1]<p[n2]);}

set<int> S;
set<int>::iterator iter;
int dfn[N],sum=0,sta[N];
void dfs3(int x){
	vector<int> g;dfn[x]=++sum;g.clear();
	for(auto y:B[x]){
		if(fa[y]==x) g.push_back(y);
	}
	sort(g.begin(),g.end(),cmp);
	for(auto y:g){
		dfs3(y);
	}
}
void dfs4(int x){
	for(auto y:B[x])
		if(fa[y]==x){
			dfs4(y);
			si[x]+=si[y];
		}
	if(p[x]==0) p[x]=dfn[x]+si[x];
}

int main()
{
	
	int n;scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),ID[a[i]]=i;
	
	for(int i=1;i<n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		B[x].push_back(y);
		B[y].push_back(x);
	}
	
	memset(bk,true,sizeof(bk));
	dfs(1);
	
	ll Ans=0;int cnt=0;
	memset(bk,true,sizeof(bk));bk[0]=false;
	for(int i=1;i<=n;i++){
		int tot=0;int t=ID[i];
		while(bk[t]) sta[++tot]=t,t=fa[t];
		for(int i=tot;i>=1;i--) p[sta[i]]=++cnt,bk[sta[i]]=false;
		
		si[ID[i]]++;Ans+=dep[ID[i]];
		
		if(!son[ID[i]]){
			son[fa[ID[i]]]--;
		}
		else{
			break;
		}
	}
	
	dfs2(1);
	dfs3(1);
	
	for(int i=1;i<=n;i++)
		if(dfn[i]!=p[i]){
			printf("NO\n");
			return 0;
		}
	memset(son,0,sizeof(son));
	memset(si,0,sizeof(si));
	memset(p,0,sizeof(p));
	for(int i=1;i<=n;i++){
		for(auto y:B[i])
			if(fa[y]==i) son[i]++;
		ID[dfn[i]]=i;
	}
	for(int i=1;i<=n;i++)
		if(son[i]==0) S.insert(dfn[i]);
	ll Anss=Ans;
	for(int i=1;i<=n;i++){
		iter=S.begin();
		int t=ID[(*iter)];S.erase(iter);
		if(Anss>dep[t]){
			p[t]=i;son[fa[t]]--;if(son[fa[t]]==0) S.insert(dfn[fa[t]]);
			si[t]++;Anss-=dep[t];
		}
		else{
			while(dep[t]!=Anss) t=fa[t];
			p[t]=i;si[t]++;
			break;
		}
	}
	dfs4(1);
	for(int i=1;i<=n;i++)
		if(p[i]!=a[i]){
			printf("NO\n");
			return 0;
		}
	
	printf("YES\n");
	printf("%lld\n",Ans);
	for(int i=1;i<=n;i++) printf("%d ",dfn[i]);
	printf("\n");
	
	return 0;
}