#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<queue>
#include<string.h>
#include<vector>
#include<set>
#include<stdlib.h>
using namespace std;
const long long mod=1000000007;
const long long inf=mod*mod;
typedef unsigned long long wolf;
vector<int>g[110000];
wolf key[110000];
int st[110000];
int ra[110000];
wolf ran[]={114514,1919810,364364,4545334};
int n;
const long long M=1000000009;
int dfs(int a,int b){
	int rem=n-1;
	for(int i=0;i<g[a].size();i++){
		if(g[a][i]==b)continue;
		int tmp=dfs(g[a][i],a);
		ra[a]=max(ra[a],tmp);
		rem-=tmp;
		st[a]+=tmp;
	}
	ra[a]=max(ra[a],rem);
	st[a]++;
	return st[a];
}
vector<int>gp;
wolf calc(int a,int b){
	vector<wolf> ch;
	for(int i=0;i<g[a].size();i++){
		if(g[a][i]==b)continue;
		ch.push_back(calc(g[a][i],a));
	}
	std::sort(ch.begin(),ch.end());
	wolf ret=ch.size()+1;
	for(int i=0;i<ch.size();i++){
		ret=(ret*mod+ch[i]*ran[i])%M;
	}
	key[a]=ret;
	return ret;
}
int ans;
void cnt(int a,int b){
	if(g[a].size()<4){
		ans++;
	}
	vector<pair<wolf,int> > v;
	for(int i=0;i<g[a].size();i++){
		if(g[a][i]==b)continue;
		v.push_back(make_pair(key[g[a][i]],g[a][i]));
	}
	std::sort(v.begin(),v.end());
	for(int i=0;i<v.size();i++){
		if(i==0||v[i].first!=v[i-1].first){
			cnt(v[i].second,a);
		}
	}
}
int main(){
	int a;scanf("%d",&a);
	for(int i=0;i<a-1;i++){
		int p,q;scanf("%d%d",&p,&q);p--;q--;
		g[p].push_back(q);g[q].push_back(p);
	}
	n=a;
	dfs(0,-1);
	int mv=999999999;
	//for(int i=0;i<a;i++)printf("%d\n",ra[i]);
	for(int i=0;i<a;i++)mv=min(mv,ra[i]);
	for(int i=0;i<a;i++)if(ra[i]==mv)gp.push_back(i);
	
	if(gp.size()>2){
		printf("yabai\n");while(1);
	}else if(gp.size()==2){
		calc(gp[0],gp[1]);
		calc(gp[1],gp[0]);
		cnt(gp[0],gp[1]);
		if(key[gp[0]]!=key[gp[1]])cnt(gp[1],gp[0]);
	}else{
		calc(gp[0],-1);
		cnt(gp[0],-1);
	}
	printf("%d\n",ans);
}