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
const long long mod=1000010007;
const long long inf=mod*mod;
vector<int> g[110000];
int c[110000];
int sz[110000];
int mc[110000];
int fi[110000];
int la[110000];
int conv[110000];
int v[110000];
int num;
void dfs(int a,int b){
	sz[a]=1;
	int now=0;
	mc[a]=-1;
	conv[num]=a;
	fi[a]=num;
	num++;
	for(int i=0;i<g[a].size();i++){
		if(g[a][i]==b)continue;
		dfs(g[a][i],a);
		sz[a]+=sz[g[a][i]];
		if(now<sz[g[a][i]]){
			now=sz[g[a][i]];
			mc[a]=g[a][i];
		}
	}
	la[a]=num;
}
int t[110000];
long long ke[110000];
long long ret[110000];
int ms;
void solve(int a,int b,int d){
	for(int i=0;i<g[a].size();i++){
		if(d==g[a][i])continue;
		if(mc[a]!=g[a][i])solve(g[a][i],0,a);
	}
	if(~mc[a])solve(mc[a],1,a);

	for(int i=0;i<g[a].size();i++){
		if(d==g[a][i])continue;
		if(mc[a]!=g[a][i])solve(g[a][i],1,a);
	}

	ke[t[c[a]]]-=c[a];
	ke[t[c[a]]+1]+=c[a];
	t[c[a]]++;
	if(t[c[a]]>ms)ms=t[c[a]];

	if(v[a]==0){
		v[a]=1;
		ret[a]=ke[ms];
	}
	if(b==0){
		for(int i=fi[a];i<la[a];i++){
			t[c[conv[i]]]--;
			ke[t[c[conv[i]]]+1]-=c[conv[i]];
			ke[t[c[conv[i]]]]+=c[conv[i]];
			if(ke[ms]==0)ms--;
		}
	}
}
int main(){
	int a;scanf("%d",&a);
	for(int i=0;i<a;i++)scanf("%d",c+i);
	for(int i=0;i<a-1;i++){
		int p,q;scanf("%d%d",&p,&q);p--;q--;
		g[p].push_back(q);
		g[q].push_back(p);
	}
	for(int i=0;i<=a;i++)ke[0]+=i;
	dfs(0,-1);
	solve(0,1,-1);
	
	for(int i=0;i<a;i++){
		if(i)printf(" ");
		printf("%I64d",ret[i]);
	}
	printf("\n");
}