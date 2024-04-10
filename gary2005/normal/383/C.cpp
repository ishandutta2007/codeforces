/*
{
######################
#       Author       #
#        Gary        #
#        2020        #
######################
*/
#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define LL long long
#define IT iterator
#define PB push_back
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define FREO freopen("check.out","w",stdout)
#define rep(a,b) for(int a=0;a<b;++a)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define POB pop_back
#define ff fflush(stdout)
#define fastio ios::sync_with_stdio(false)
#define R(a) cin>>a
#define R2(a,b) cin>>a>>b
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
/*}
*/
int heavy[200000+20],siz[200000+20],dfn[200000+20],depth[200000+20],top[200000+20];
int n,m;
vector<int> g[200000+20];
struct BIT{
	int bit[200000+10]={0};
	int sum(int i){
		int s=0;
		while(i>0){
			s+=bit[i];
			i-=i&(-i);
		}
		return s;
	}
	void add(int i,int x=1){
		while(i<=n){
			bit[i]+=x;
			i+=i&(-i);	
		}
	}
	int query(int l,int r){
		return sum(r)-sum(l-1);
	}
}bit[2];
void dfs(int now,int pre){
	siz[now]=1;
	for(auto it:g[now]){
		if(it!=pre){
//			cout<<now<<" "<<it<<endl;
			depth[it]=depth[now]^1;
			dfs(it,now);
			siz[now]+=siz[it];
		}
	}
	for(auto it:g[now]){
		if(it!=pre){
			if(!heavy[now]||siz[heavy[now]]<siz[it]){
				heavy[now]=it;
			}
		} 
	}
}
int cnt=0;
int fa[200000+20];
void dfs2(int now,int pre){
	dfn[now]=++cnt;
	fa[now]=pre;
	if(heavy[now])	
	{
		top[heavy[now]]=top[now];
		dfs2(heavy[now],now);
	}
	for(auto it:g[now]){
		if(it!=pre&&it!=heavy[now]){
			top[it]=it;
			dfs2(it,now);
		}
	}
}
int a[200000+20];
int main(){
	fastio;
	R2(n,m);
	rb(i,1,n) R(a[i]);
	rb(i,2,n){
		int u,v;
		R2(u,v);
		g[u].PB(v);
		g[v].PB(u);
	}
	dfs(1,0);
	top[1]=1;
	dfs2(1,0);
	rb(i,1,m)
	{
		int ty;
		R(ty);
		if(ty==1){
			int x,val;
			R2(x,val);
			bit[depth[x]].add(dfn[x],val);
		}
		else{
			int x;
			R(x);
			int rest=0;
			int now=x;
			do{
				rest+=bit[depth[x]].query(dfn[top[now]],dfn[now]);
				rest-=bit[depth[x]^1].query(dfn[top[now]],dfn[now]);
				now=fa[top[now]];
			} while(now);
			cout<<rest+a[x]<<endl;
		}
	}
	return 0;
}
/** 
  *
  *
  *
  *
  **/