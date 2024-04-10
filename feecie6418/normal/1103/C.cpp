#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pr;
const int mod=998244353;
vector<int> g[250005];
int n,m,K,vst[250005],d[250005],fa[250005],leaf[250005];
void dfs(int x,int f){
	d[x]=d[f]+1,fa[x]=f,vst[x]=1,leaf[x]=1;
	if(1ll*d[x]*K>=n){
		puts("PATH");
		cout<<d[x]<<'\n';
		while(x)cout<<x<<' ',x=fa[x];
		exit(0);
	}
	for(int y:g[x]){
		if(vst[y])continue;
		dfs(y,x),leaf[x]=0;
	}
}
int main(){
	scanf("%d%d%d",&n,&m,&K);
	for(int i=1,x,y;i<=m;i++)scanf("%d%d",&x,&y),g[x].push_back(y),g[y].push_back(x);
	dfs(1,0);
	puts("CYCLES");
	for(int i=1;i<=n;i++){
		if(!leaf[i])continue;
		K--;
		int u=0,v=0;
		for(int j:g[i]){
			if(j==fa[i])continue;
			if(!u)u=j;
			else v=j;
		}
		if((d[i]-d[u]+1)%3){
			cout<<d[i]-d[u]+1<<'\n';
			int p=i;
			while(1){
				cout<<p<<' ';
				if(p==u)break;
				p=fa[p];
			}
			puts("");
		}
		else if((d[i]-d[v]+1)%3){
			cout<<d[i]-d[v]+1<<'\n';
			int p=i;
			while(1){
				cout<<p<<' ';
				if(p==v)break;
				p=fa[p];
			}
			puts("");
		}
		else {
			if(d[u]>d[v])swap(u,v);
			cout<<d[v]-d[u]+2<<'\n';
			cout<<i<<' ';
			int p=v;
			while(1){
				cout<<p<<' ';
				if(p==u)break;
				p=fa[p];
			}
			puts("");
		}
		if(!K)break;
	}
}