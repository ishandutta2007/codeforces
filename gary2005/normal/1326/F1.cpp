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
const int MAXN=18;
bool e[MAXN][MAXN];
int cnt[1<<MAXN];
int n;
void IFWT(vector<LL>& num,int len){
	rep(i,len) rep(mask,1<<len) if((mask>>i)&1);
	else{
		num[mask]-=num[mask|(1<<i)];
	}
}
vector<LL> rest;
LL dp[1<<MAXN][MAXN];
LL sum[1<<MAXN];
LL f[20][1<<MAXN];
LL pre[1<<MAXN][MAXN+2];
vector<int> now;
map<vector<int>,LL> mem;
void dfs(int rst,int pre_,int stp=0){
	if(rst==0){
		LL rst=0;		
		rep(mask,1<<n){
			if(abs(n-cnt[mask])&1){
				rst-=f[stp][mask];
			}
			else{
				rst+=f[stp][mask];
			}
		}
		mem[now]=rst;
		return ;
	}
	rb(i,pre_,rst){
		now.PB(i);
		rep(mask,1<<n) f[stp+1][mask]=f[stp][mask]*pre[mask][i];
		dfs(rst-i,i,stp+1);
		now.POB();
	}
}
int main(){
	scanf("%d",&n);
	rep(i,n) rep(j,n){
		char c;cin>>c;
		e[i][j]=c-'0';
	}
	rep(i,n) dp[1<<i][i]=1;
	rep(mask,1<<n){
		rep(j,n){
			if((mask>>j)&1);
			else continue;
			rep(k,n){
				if(e[j][k])
					dp[mask][j]+=dp[mask^(1<<j)][k];
			}
			sum[mask]+=dp[mask][j];
		}
		cnt[mask]=__builtin_popcount(mask);
		pre[mask][cnt[mask]]+=sum[mask];
	}
	rb(cnt,1,n){//
		rep(j,n)
			rep(mask,1<<n)
				if((mask>>j)&1) pre[mask][cnt]+=pre[mask^(1<<j)][cnt];
	}
	fill(f[0],f[0]+(1<<n),1);
	dfs(n,1);
	rest.resize(1<<(n-1));
	rep(mask,1<<(n-1)){
		vector<int> nowv;
		int pre=1;
		rep(j,n-1){
			if((mask>>j)&1);
			else nowv.PB(pre),pre=0;
			pre++;
		}
		nowv.PB(pre);
		sort(ALL(nowv));
		rest[mask]=mem[nowv];
	}
	IFWT(rest,n-1);
	rep(i,1<<(n-1)) printf("%lld ",rest[i]);
	return 0;
}