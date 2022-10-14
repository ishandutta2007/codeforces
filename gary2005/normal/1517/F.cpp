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
int x;
const int MAXN=303;
const int MOD=998244353;
int quick(int A,int B){
	if(B==0) return 1;
	int tmp=quick(A,B>>1);
	tmp=1ll*tmp*tmp%MOD;
	if(B&1) tmp=1ll*tmp*A%MOD;
	return tmp;
}
int inv(int A){
	return quick(A,MOD-2);
}
int cnt[MAXN];
vector<int> g[MAXN];
int n;
void init(int now,int pre){
	for(auto &it:g[now]){
		if(it!=pre) init(it,now); 
	}
	for(auto &it:g[now]){
		if(it==pre){
			swap(it,g[now].back());	
			break;
		}
	}
	if(pre) g[now].POB();
}
int dp[MAXN][MAXN<<1][2];
void trans(int now){
	if(g[now].empty()){
		rb(i,0,n) dp[now][MAXN-i][i==0]=(i>x? 2:1);
		return ;
	}
	for(auto it:g[now]){
		trans(it);
	}
	rb(j,1,n){
		int nw[2]={1,0},nw2[2]={1,0};
		rep(k,g[now].size()){
			int tmp[2]={0,0};
			tmp[0]=(
			1ll*nw[0]*(1ll*dp[g[now][k]][j-1+MAXN][0]+dp[g[now][k]][j+MAXN][0]+dp[g[now][k]][j+1+MAXN][0]+dp[g[now][k]][-j-1+MAXN][0])+
			1ll*nw[1]*(1ll*dp[g[now][k]][j-1+MAXN][1]+dp[g[now][k]][j+MAXN][1]+dp[g[now][k]][j+1+MAXN][1]+dp[g[now][k]][-j-1+MAXN][1])
			)%MOD;
			tmp[1]=(
			1ll*nw[1]*(1ll*dp[g[now][k]][j-1+MAXN][0]+dp[g[now][k]][j+MAXN][0]+dp[g[now][k]][j+1+MAXN][0]+dp[g[now][k]][-j-1+MAXN][0])+
			1ll*nw[0]*(1ll*dp[g[now][k]][j-1+MAXN][1]+dp[g[now][k]][j+MAXN][1]+dp[g[now][k]][j+1+MAXN][1]+dp[g[now][k]][-j-1+MAXN][1])
			)%MOD;
			nw[0]=tmp[0];
			nw[1]=tmp[1];
			tmp[0]=tmp[1]=0;
			tmp[0]=(
			1ll*nw2[0]*(1ll*dp[g[now][k]][j+MAXN][0]+dp[g[now][k]][j+1+MAXN][0]+dp[g[now][k]][-j-1+MAXN][0])+
			1ll*nw2[1]*(1ll*dp[g[now][k]][j+MAXN][1]+dp[g[now][k]][j+1+MAXN][1]+dp[g[now][k]][-j-1+MAXN][1])
			)%MOD;
			tmp[1]=(
			1ll*nw2[1]*(1ll*dp[g[now][k]][j+MAXN][0]+dp[g[now][k]][j+1+MAXN][0]+dp[g[now][k]][-j-1+MAXN][0])+
			1ll*nw2[0]*(1ll*dp[g[now][k]][j+MAXN][1]+dp[g[now][k]][j+1+MAXN][1]+dp[g[now][k]][-j-1+MAXN][1])
			)%MOD;
			nw2[0]=tmp[0];
			nw2[1]=tmp[1];
		}
		dp[now][j+MAXN][0]=(nw[0]+MOD-nw2[0])%MOD;
		dp[now][j+MAXN][1]=(nw[1]+MOD-nw2[1])%MOD;
		if(j>x){
			dp[now][j+MAXN][0]=1ll*dp[now][j+MAXN][0]*2%MOD;
			dp[now][j+MAXN][1]=1ll*dp[now][j+MAXN][1]*2%MOD;
		}
	}
	dp[now][MAXN][1]=1;
	for(auto it:g[now]){
		int nw[2]={0,0};
		rep(z,2){
			rep(t,2){
				(nw[t^z]+=1ll*dp[now][MAXN][z]*(1ll*dp[it][MAXN-1][t]+dp[it][MAXN][t]+dp[it][MAXN+1][t])%MOD)%=MOD;
			}
		}
		dp[now][MAXN][0]=nw[0];
		dp[now][MAXN][1]=nw[1];
	}
	rb(j,1,n){
		dp[now][MAXN-j][0]=1;
		for(auto it:g[now]){
			int nw[2]={0,0};
			nw[0]=(1ll*dp[now][MAXN-j][0]*(1ll*dp[it][MAXN+j][0]+dp[it][MAXN+j+1][0]+dp[it][-j-1+MAXN][0])+
			1ll*dp[now][MAXN-j][1]*(1ll*dp[it][MAXN+j][1]+dp[it][MAXN+j+1][1]+dp[it][-j-1+MAXN][1]))%MOD;
			nw[1]=(1ll*dp[now][MAXN-j][1]*(1ll*dp[it][MAXN+j][0]+dp[it][MAXN+j+1][0]+dp[it][-j-1+MAXN][0])+
			1ll*dp[now][MAXN-j][0]*(1ll*dp[it][MAXN+j][1]+dp[it][MAXN+j+1][1]+dp[it][-j-1+MAXN][1]))%MOD;
			dp[now][MAXN-j][0]=nw[0];
			dp[now][MAXN-j][1]=nw[1];
		}
		if(j>x){
			dp[now][MAXN-j][0]=1ll*dp[now][MAXN-j][0]*2%MOD;
			dp[now][MAXN-j][1]=1ll*dp[now][MAXN-j][1]*2%MOD;
		}
	}
}
int main(){
	scanf("%d",&n);
	rb(i,1,n-1){
		int u,v;
		scanf("%d%d",&u,&v);
		g[u].PB(v);
		g[v].PB(u);
	}
	init(1,0);
	int rest=0;
	for(x=0;x<=n;++x){
		memset(dp,0,sizeof(dp));
		trans(1);
		rb(i,0,n) (cnt[x]+=dp[1][i+MAXN][1])%=MOD,(cnt[x]+=MOD-dp[1][i+MAXN][0])%=MOD;
	}
	for(x=0;x<=n;++x) (cnt[x]+=MOD-cnt[x+1])%=MOD,rest+=1ll*cnt[x]*x%MOD,rest%=MOD;
	cout<<1ll*(rest-1)*inv(quick(2,n))%MOD<<endl;
	return 0;
}