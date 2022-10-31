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
int c[210000];
vector<pair<int,int> >g[210000];
long long tmp[210000];
int par[210000];
int ans[210000];
void dfs(int a,int b){
	for(int i=0;i<g[a].size();i++){
		tmp[b+1]=tmp[b]+g[a][i].second;
		par[b+1]=g[a][i].first;
		dfs(g[a][i].first,b+1);
		ans[a]+=ans[g[a][i].first];
	}
	long long L=tmp[b]-c[a];
	int at=lower_bound(tmp,tmp+b+1,L)-tmp;
	ans[a]++;
	if(at)ans[par[at-1]]--;
}
int main(){
	int a;scanf("%d",&a);
	for(int i=0;i<a;i++)scanf("%d",c+i);
	for(int i=0;i<a-1;i++){
		int p,q;scanf("%d%d",&p,&q);
		p--;
		g[p].push_back(make_pair(i+1,q));
	}
	dfs(0,0);
	for(int i=0;i<a;i++){
		if(i)printf(" ");
		printf("%d",ans[i]-1);
	}
	printf("\n");
}