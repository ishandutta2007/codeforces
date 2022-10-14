/*
{
######################
#       Author       #
#        Gary        #
#        2021        #
######################
*/
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
//inline int read(){
//    int x=0;
//    char ch=getchar();
//    while(ch<'0'||ch>'9'){
//        ch=getchar();
//    }
//    while(ch>='0'&&ch<='9'){
//        x=(x<<1)+(x<<3)+(ch^48);
//        ch=getchar();
//    }
//    return x;
//}
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
/*}
*/
const int MAXN=1e5+233;
int n,k;
vector<int> g[MAXN];
int rest[MAXN];
int a[MAXN];
int dp[MAXN][44];
void merge(int u,int v){
	rep(i,2*k){
		dp[u][(i+1)%(2*k)]^=dp[v][i];
	}
}
void dfs(int now,int pre){
	for(auto it:g[now]){
		if(it!=pre){
			dfs(it,now);
			merge(now,it);
		}
	}
	dp[now][0]^=a[now];
}
void cr(int now,int pre){
	rest[now]=0;
	rep(i,2*k) if(i>=k) rest[now]^=dp[now][i];
	int odp[44];
	rep(i,2*k) odp[i]=dp[now][i];
	for(auto it:g[now]){
		if(it!=pre){
			rep(i,2*k) dp[now][i]=odp[i];
			merge(now,it);
			merge(it,now);
			cr(it,now);
		}
	}
}
int main(){
	scanf("%d%d",&n,&k);
	rb(i,2,n){
		int u,v;
		scanf("%d%d",&u,&v);
		g[u].PB(v);
		g[v].PB(u); 
	}
	rb(i,1,n) scanf("%d",&a[i]);
	dfs(1,0);
	cr(1,0);
	rb(i,1,n){
		printf("%d ",(rest[i]>0)); 
	}
	return 0;
}