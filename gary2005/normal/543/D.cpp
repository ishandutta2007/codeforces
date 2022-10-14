/*
{
######################
#       Author       #
#        Gary        #
#        2020        #
######################
*/
//#pragma GCC target ("avx2")
//#pragma GCC optimization ("O3")
//#pragma GCC optimization ("unroll-loops")
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
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
/*}
*/
const int MAXN=200000+20;
const int MOD=1e9+7;
vector<int> g[MAXN];
int n,rest[MAXN],dp[MAXN][2],val[MAXN];
vector<int> pre[MAXN];
vector<int> suf[MAXN];
void run(int now,int preF){
	val[now]=1;
	for(auto it:g[now]){
		if(it!=preF){
			run(it,now);
			val[now]=1ll*val[now]*(dp[it][0]+dp[it][1])%MOD;
			pre[now].PB(val[now]);
		}
	}
	int st=1;
	if(!g[now].empty())
		rl(i,g[now].size()-1,0){
			if(g[now][i]!=preF){
				st=1ll*st*(dp[g[now][i]][0]+dp[g[now][i]][1])%MOD;
				suf[now].PB(st);
			}
		}
	reverse(ALL(suf[now]));
	dp[now][1]=val[now];
	dp[now][0]=1;
}
void change_root(int now,int preF,int by_f=1){
	rest[now]=dp[now][1]+dp[now][0]-1;
	int z=0;
	for(auto it:g[now]){
		if(it!=preF){
			int tmp=1ll;
			if(z){
				tmp=1ll*tmp*pre[now][z-1]%MOD;
			}
			if(z+1!=suf[now].size()){
				tmp=1ll*tmp*suf[now][z+1]%MOD;
			}
			tmp=1ll*tmp*by_f%MOD; 
			val[it]=1ll*val[it]*(tmp+1)%MOD;
//			cout<<now<<' '<<it<<' '<<tmp<<' '<<val[it]<<endl;
			dp[it][1]=val[it];
			change_root(it,now,tmp+1);
			z++;
		}
	}
}
int main(){
	scanf("%d",&n);
	rb(i,2,n){
		int pi;scanf("%d",&pi);
		g[pi].PB(i),g[i].PB(pi);
	}
	run(1,0);
	change_root(1,0);
	rb(i,1,n) printf("%d ",rest[i]);
	return 0;
}
/** 
  *
  *
  *
  *
  **/