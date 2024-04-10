/*
{By GWj
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
int n,a,b,da,db;
vector<int> g[100000+10];
int dis1[100000+10],dis2[100000+10];
mp maxi;
int dis;
int maxx;
void dfs(int now,int pre,int dd=0){
	check_max(maxx,dd);
	if(now==a){
		dis=dd;
	}
	for(auto it:g[now]){
		if(it!=pre){
			dfs(it,now,dd+1);
		}
	}
}
void dfs1(int now,int pre,int dd=0){
	dis1[now]=dd;
	for(auto it:g[now]){
		if(it!=pre){
			dfs1(it,now,dd+1);
		}
	}
}
void dfs2(int now,int pre,int dd=0){
	dis2[now]=dd;
	for(auto it:g[now]){
		if(it!=pre){
			dfs2(it,now,dd+1);
		}
	}
}
void dfs3(int now,int pre,int dd=0){
	maxi=max(maxi,II(dd,now));
	for(auto it:g[now]){
		if(it==pre){
			continue;
		}
		dfs3(it,now,dd+1);
	}
}
void solve(){
	maxx=0;
	maxi=II(0,b);
	cin>>n>>a>>b>>da>>db;
	rb(i,1,n)
		g[i].clear();
	rb(i,2,n){
			int u,v;
			R2(u,v);
			g[u].PB(v);
			g[v].PB(u);
		}
	dfs(b,0);
	dfs1(a,0);
	dfs2(b,0);
	dfs3(b,0);
	dfs3(maxi.SEC,0);
	maxi.FIR=max(maxi.FIR,maxx);
	if(dis>da&&db>da+da&&maxi.FIR>da+da){
		cout<<"Bob"<<endl;
	}
	else{
		cout<<"Alice"<<endl;
	}
}
int main(){
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}