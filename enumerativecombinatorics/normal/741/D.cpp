#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<queue>
#include<string.h>
#include<vector>
#include<set>
using namespace std;
const long long mod=1000000007;
const long long inf=mod*mod;
vector<pair<int,char> >g[510000];
char in[510000];
int ans[510000];
int dep[510000];
int sz[510000];
int key[510000];
void dfs(int a){
	sz[a]=1;
	for(int i=0;i<g[a].size();i++){
		dep[g[a][i].first]=dep[a]+1;
		key[g[a][i].first]=key[a]^(1<<(g[a][i].second-'a'));
		dfs(g[a][i].first);
		
		sz[a]+=sz[g[a][i].first];
	}
}
int wolf[1<<22];
vector<int>del;
vector<int>vis;
void dfs2(int a,int b){
	for(int i=0;i<g[a].size();i++){
		dfs2(g[a][i].first,b);
	}
	for(int k=0;k<23;k++){
		int x=key[a];
		if(k<22)x^=(1<<k);
		ans[b]=max(ans[b],dep[a]+wolf[x]-2*dep[b]);
	}
}
void dfs3(int a){
	for(int i=0;i<g[a].size();i++){
		dfs3(g[a][i].first);
	}
	if(wolf[key[a]]<0)del.push_back(key[a]);
	wolf[key[a]]=max(wolf[key[a]],dep[a]);
}
void calc(int a){
	int lc=-1;
	int val=-1;
	for(int i=0;i<g[a].size();i++){
		if(val<sz[g[a][i].first]){
			lc=g[a][i].first;
			val=sz[g[a][i].first];
		}
	}
	for(int i=0;i<g[a].size();i++){
		if(g[a][i].first==lc)continue;
		calc(g[a][i].first);
		for(int j=0;j<del.size();j++){
			wolf[del[j]]=-mod;
		}
		del.clear();
	}
	if(~lc){
		calc(lc);
		for(int i=0;i<g[a].size();i++){
			if(g[a][i].first!=lc){
				dfs2(g[a][i].first,a);
				dfs3(g[a][i].first);
			}
		}
	}
	for(int i=0;i<23;i++){
		int x=key[a];
		if(i<22)x^=(1<<i);
		ans[a]=max(ans[a],dep[a]+wolf[x]-dep[a]*2);
	}

	if(wolf[key[a]]<0)del.push_back(key[a]);
	wolf[key[a]]=max(wolf[key[a]],dep[a]);
	
	for(int i=0;i<g[a].size();i++)ans[a]=max(ans[a],ans[g[a][i].first]);
}
int main(){
	int a;scanf("%d",&a);
	for(int i=0;i<a-1;i++){
		int p;
		scanf("%d%s",&p,in+i);
		p--;
		g[p].push_back(make_pair(i+1,in[i]));
	}
	dfs(0);
	for(int i=0;i<(1<<22);i++)wolf[i]=-mod;
	calc(0);
	
	for(int i=0;i<a;i++){
		if(i)printf(" ");
		printf("%d",ans[i]);
	}
	printf("\n");
}