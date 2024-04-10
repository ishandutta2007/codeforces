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
vector<int> g[100000+20];
int siz[100000+20];
void dfs(int now,int pre=0){
	for(auto it:g[now]){
		if(it!=pre){
			dfs(it,now);
			siz[now]+=siz[it];
		}
	}
	siz[now]++;
}
vector<mp> v;
void change(int now,int prev=0){
	int sv=siz[now];
	int maxi=0;
	for(auto it:g[now]){
		check_max(maxi,siz[it]);
	}
	v.PB(II(maxi,now));
	for(auto it:g[now]){
		if(it!=prev){
			siz[now]-=siz[it];
			siz[it]+=siz[now];
			change(it,now);
			siz[now]=sv;
		}
	}
}
void solve(){
	int n;
	R(n);
	v.clear();
	rb(i,1,n)
		g[i].clear(),siz[i]=0;
	rb(i,2,n){
		int u,v;
		R2(u,v);
		g[u].PB(v);
		g[v].PB(u);
	}
	dfs(1,0);
	change(1,0);
	sort(ALL(v));
	if(v[0].FIR==v[1].FIR){
		if(g[v[0].SEC][0]==v[1].SEC){
			g[v[0].SEC][0]=g[v[0].SEC][1];
		}
		cout<<v[0].SEC<<" "<<g[v[0].SEC][0]<<endl<<g[v[0].SEC][0]<<" "<<v[1].SEC<<endl;
	}
	else{
		cout<<1<<" "<<g[1][0]<<endl<<1<<" "<<g[1][0]<<endl;
	}
}
int main(){
	fastio;
	int t;
	R(t);
	while(t--){
		solve();
	}
	return 0;
}