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
vector<int>g[310000];
int sz[310000];
int num;
int L[310000];
int R[310000];
int conv[310000];
int nx[310000];
void dfs(int a){
	sz[a]=1;
	L[a]=num;
	conv[num]=a;
	int mn=0;

	num++;
	for(int i=0;i<g[a].size();i++){
		dfs(g[a][i]);
		sz[a]+=sz[g[a][i]];
		if(mn<sz[g[a][i]]){
			mn=sz[g[a][i]];
			nx[a]=i;
		}
	}
	R[a]=num;
}
int ans[310000];
set<pair<pair<int,int>,int> > S;
set<pair<pair<int,int>,int> > T;
int mx[310000];
void solve(int a,int b){
	int to=-1;

	for(int i=0;i<g[a].size();i++){
		mx[a]=max(mx[a],sz[g[a][i]]);
		if(nx[a]==i){
			to=g[a][i];continue;
		}
		solve(g[a][i],0);

	}
	if(~to)solve(to,1);
	for(int i=0;i<g[a].size();i++){
		if(to==g[a][i])continue;
		solve(g[a][i],1);
	}
	if(!~ans[a]){

	T.insert(make_pair(make_pair(mx[a],sz[a]),a));
	S.insert(make_pair(make_pair(sz[a],mx[a]),a));
	int del=0;
	for(set<pair<pair<int,int>,int> > ::iterator it=S.begin();it!=S.end();it++){
		if((*it).first.first*2<sz[a])del++;
		else break;
	}
	for(int i=0;i<del;i++){
		pair<pair<int,int>,int> tmp=*(S.begin());
		S.erase(tmp);
		swap(tmp.first.first,tmp.first.second);
		T.erase(tmp);
	}
		ans[a]=(*(T.begin())).second;
	}
//	printf("%d: %d %d %d\n",a,T.begin()->first.first,T.begin()->first.second,T.begin()->second);
	if(b==0){
		for(int i=L[a];i<R[a];i++){
			T.erase(make_pair(make_pair(mx[conv[i]],sz[conv[i]]),conv[i]));
			S.erase(make_pair(make_pair(sz[conv[i]],mx[conv[i]]),conv[i]));
		}
	}
}
int main(){
	int a,b;scanf("%d%d",&a,&b);
	for(int i=0;i<a-1;i++){
		int p;scanf("%d",&p);p--;
		g[p].push_back(i+1);
	}
	for(int i=0;i<a;i++)ans[i]=-1;
	dfs(0);
	solve(0,1);
	while(b--){
		int p;scanf("%d",&p);p--;printf("%d\n",ans[p]+1);
	}
}