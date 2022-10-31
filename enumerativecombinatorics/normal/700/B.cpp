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
int v[210000];
vector<int>g[221000];
long long ret=0;
int sz[221000];
int M;
void dfs(int a,int b){
	for(int i=0;i<g[a].size();i++){
		if(b==g[a][i])continue;
		dfs(g[a][i],a);
		sz[a]+=sz[g[a][i]];
		ret+=min(sz[g[a][i]],M-sz[g[a][i]]);
	}
	if(v[a])sz[a]++;

}
int main(){
	int a,b;
	scanf("%d%d",&a,&b);
	M=b*2;
	for(int i=0;i<b*2;i++){
		int p;scanf("%d",&p);p--;v[p]++;
	}
	for(int i=0;i<a-1;i++){
		int p,q;scanf("%d%d",&p,&q);p--;q--;
		g[p].push_back(q);
		g[q].push_back(p);
	}
	dfs(0,-1);
	printf("%I64d\n",ret);
}