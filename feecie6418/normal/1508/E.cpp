#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pr;
int n,a[300005],fa[300005],dfn1[300005],dfn2[300005],d[300005],s1,s2,pos[300005];
vector<int> g[300005];
ll ans=0;
void dfs1(int x,int f){
	dfn1[x]=++s1,fa[x]=f,d[x]=d[f]+1;
	sort(g[x].begin(),g[x].end(),[](int x,int y){return a[x]<a[y];});
	for(int y:g[x]){
		if(y==f)continue;
		dfs1(y,x);
	}
	dfn2[x]=++s2;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1,x,y;i<n;i++){
		scanf("%d%d",&x,&y);
		g[x].push_back(y),g[y].push_back(x);
	}
	dfs1(1,0);
	if(a[1]==1){
		for(int i=1;i<=n;i++)if(a[i]!=dfn1[i])return puts("NO"),0;
		puts("YES\n0");
		for(int i=1;i<=n;i++)printf("%d ",dfn1[i]);
		puts("");
		return 0;
	}
	int x=0,I=a[1]-1,y=0;
	for(int i=1;i<=n;i++){
		if(a[i]==I)x=i;
		if(dfn2[i]==I)y=i;
	}
	bool ok=0;
	while(y){
		if(y==x)ok=1;
		y=fa[y];
	}
	if(!ok)return puts("NO"),0;
	while(x>1){
		if(a[fa[x]]<a[x])return puts("NO"),0;
		swap(a[x],a[fa[x]]),x=fa[x],ans++;
	}
	for(int i=1;i<=n;i++)pos[a[i]]=i;
	for(int i=1;i<=n;i++){
		if(a[i]<I&&a[i]!=dfn2[i])return puts("NO"),0;
		if(a[i]<I)ans+=d[i]-1;
	}
	vector<pr> v;
	for(int i=1;i<=n;i++)if(dfn2[i]>=I)v.push_back(pr(dfn1[i],i));
	sort(v.begin(),v.end());
	for(int i=0;i<v.size();i++)if(v[i].second!=pos[i+I])return puts("NO"),0;
	puts("YES");
	cout<<ans<<'\n';
	for(int i=1;i<=n;i++)printf("%d ",dfn1[i]);
	puts("");
}