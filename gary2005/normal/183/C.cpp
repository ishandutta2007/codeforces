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
int n;int m;
vector<int> g[100000+1],rg[100000+1];
bool vis[100000+1];
int is[100000+1];
int rest=0;
void dfs(int now){
	vis[now]=1;
	for(auto it:g[now]){
		if(!vis[it]){
			is[it]=is[now]+1;
			dfs(it);
		}
		else{
			rest=(rest? __gcd(rest,abs(is[now]+1-is[it])):abs(is[now]+1-is[it]));
			is[it]=is[now]+1;
		}
	}
	for(auto it:rg[now]){
		if(!vis[it]){
			is[it]=is[now]-1;
			dfs(it);
		}
		else{
			rest=(rest? __gcd(rest,abs(is[now]-1-is[it])):abs(is[now]-1-is[it]));
			is[it]=is[now]-1;
		}
	}
}
int main(){
	fastio;
	cin>>n>>m;
	rb(i,1,m){
		int u,v;
		R2(u,v);
		g[u].PB(v);
		rg[v].PB(u);
		if(u==v){
			cout<<1<<endl;
			return 0; 
		}
	}
	rb(i,1,n){
		if(!vis[i]){
			is[i]=1;
			dfs(i);
		}
	}
	if(rest==0){
		rest=n;
	}
	cout<<rest<<endl;
	return 0;
}