#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<queue>
#include<string.h>
#include<vector>
#include<set>
#include<map>
#include<stdlib.h>
using namespace std;
const long long mod=1000000007;
const long long inf=mod*mod;
vector<int>g[410000];
pair<int,int> z[820000];
int L[820000];
int R[820000];
int dp[820000][2];
int v[820000];
int num;
void dfs(int a,int b){
	for(int i=0;i<g[a].size();i++){
		L[num]=a;R[num]=g[a][i];
		z[num++]=make_pair(a,g[a][i]);
	}
	for(int i=0;i<g[a].size();i++){
		if(g[a][i]==b)continue;
		dfs(g[a][i],a);
	}
}
int n;
int vis[410000];
int ans[410000];
int un[410000];
int fin(int a,int b){
	return lower_bound(z,z+num,make_pair(a,b))-z;
}
pair<int,int> ef[410000][2];
pair<int,int> tm[410000][2];
pair<int,int> calc(int a,int b){
	int at=lower_bound(z,z+num,make_pair(a,b))-z;
	if(v[at])return make_pair(dp[at][0],dp[at][1]);
	v[at]=1;
	if(!vis[a]){
		vis[a]=1;

		for(int i=0;i<g[a].size();i++){
			if(g[a][i]==b){
				un[a]=i;
				continue;
			}
			pair<int,int> tmp=calc(g[a][i],a);
			dp[at][0]+=tmp.first;
			if(ef[a][0].first<tmp.first-tmp.second){
				ef[a][1]=ef[a][0];ef[a][0]=make_pair(tmp.first-tmp.second,g[a][i]);
			}else if(ef[a][1].first<tmp.first-tmp.second){
				ef[a][1]=make_pair(tmp.first-tmp.second,g[a][i]);
			}
			if(tm[a][0].first<tmp.first){
				tm[a][1]=tm[a][0];tm[a][0]=make_pair(tmp.first,g[a][i]);
			}else if(tm[a][1].first<tmp.first){
				tm[a][1]=make_pair(tmp.first,g[a][i]);
			}
		}
		dp[at][0]++;
	}else{
		if(un[a]!=-1){
			int ind=un[a];
			un[a]=-1;
			pair<int,int> tmp=calc(g[a][ind],a);
			if(ef[a][0].first<tmp.first-tmp.second){
				ef[a][1]=ef[a][0];ef[a][0]=make_pair(tmp.first-tmp.second,g[a][ind]);
			}else if(ef[a][1].first<tmp.first-tmp.second){
				ef[a][1]=make_pair(tmp.first-tmp.second,g[a][ind]);
			}
			if(tm[a][0].first<tmp.first){
				tm[a][1]=tm[a][0];tm[a][0]=make_pair(tmp.first,g[a][ind]);
			}else if(tm[a][1].first<tmp.first){
				tm[a][1]=make_pair(tmp.first,g[a][ind]);
			}
		}
		dp[at][0]=n-dp[fin(b,a)][0];
	}
	int ef1,tm1;
	if(ef[a][0].second!=b)ef1=ef[a][0].first;
	else ef1=ef[a][1].first;
	if(tm[a][0].second!=b)tm1=tm[a][0].first;
	else tm1=tm[a][1].first;
	dp[at][1]=dp[at][0]-ef1;
	if(tm1<=n/2)dp[at][1]=min(dp[at][1],dp[at][0]-tm1);
	
	//printf("%d %d: %d %d\n",a,b,dp[at][0],dp[at][1]);
	return make_pair(dp[at][0],dp[at][1]);
}
int main(){
	int a;scanf("%d",&a);
	n=a;
	for(int i=0;i<a-1;i++){
		int p,q;scanf("%d%d",&p,&q);
		p--;q--;
		g[p].push_back(q);
		g[q].push_back(p);
	}
	dfs(0,-1);
	std::sort(z,z+num);
	for(int i=0;i<num;i++){
		L[i]=z[i].first;R[i]=z[i].second;
	}
	for(int i=0;i<num;i++){
		if(v[i])continue;
		calc(L[i],R[i]);
	}
	for(int i=0;i<a;i++){
		bool ok=true;
		for(int j=0;j<g[i].size();j++){
			int at=lower_bound(z,z+num,make_pair(g[i][j],i))-z;
			if(dp[at][1]>a/2)ok=false;
		}
		if(ok)ans[i]=1;
	}
	for(int i=0;i<a;i++){
		if(i)printf(" ");
		printf("%d",ans[i]);
	}
	printf("\n");
}