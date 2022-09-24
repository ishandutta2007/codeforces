#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int id[300005],dfn[300005],size[300005],n,sign,c[300005],ans;
vector<int> g1[300005],g2[300005];
set<int> s;
void U(int x,int k){
	while(x<=n)c[x]+=k,x+=x&-x;
}
int Q(int x){
	int r=0;
	while(x)r+=c[x],x-=x&-x;
	return r;
}
void dfs2(int x){
	dfn[x]=++sign,size[x]=1,id[sign]=x;
	for(int y:g2[x])dfs2(y),size[x]+=size[y];
}
void dfs1(int x){
	int fl=0,rep=0;
	if(Q(dfn[x]+size[x]-1)-Q(dfn[x]-1)==0){
		auto it=s.lower_bound(dfn[x]);
		if(it!=s.begin()){
			int p=id[*--it];
			if(dfn[p]<=dfn[x]&&dfn[x]<dfn[p]+size[p])U(dfn[rep=p],-1),s.erase(it);
		}
		s.insert(dfn[x]),U(dfn[x],1),fl=1;
	}
	ans=max(ans,(int)s.size());
	for(int y:g1[x])dfs1(y);
	if(fl){
		s.erase(dfn[x]),U(dfn[x],-1);
		if(rep)s.insert(dfn[rep]),U(dfn[rep],1);
	}
}
void Solve(){
	scanf("%d",&n);
	for(int i=2,x;i<=n;i++)scanf("%d",&x),g1[x].push_back(i);
	for(int i=2,x;i<=n;i++)scanf("%d",&x),g2[x].push_back(i);
	dfs2(1),dfs1(1),cout<<ans<<'\n';
	for(int i=1;i<=n;i++)g1[i].clear(),g2[i].clear(),id[i]=dfn[i]=size[i]=c[i]=0;
	sign=ans=0,assert(!s.size());
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--)Solve();
}