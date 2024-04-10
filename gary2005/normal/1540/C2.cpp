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
const int MAXN=101;
const int MOD=1e9+7;
int n,c[MAXN],b[MAXN],q,dp[MAXN][MAXN*MAXN],pre2[MAXN],ans[MAXN*MAXN];
int query(int x){
	memset(dp,0,sizeof(dp));
	dp[0][0]=1;
	rb(i,1,n){
		int sum=0;
		rb(j,0,100*100){
			(sum+=dp[i-1][j])%=MOD;
			if(j>=c[i]+1) (sum+=MOD-dp[i-1][j-c[i]-1])%=MOD;
			if(j<pre2[i]+i*x) dp[i][j]=0;
			else dp[i][j]=sum;
		}
	}
	int Ans=0;
	rb(j,0,100*100){
		(Ans+=dp[n][j])%=MOD;
	}
	return Ans;
}
int main(){
	scanf("%d",&n);
	rb(i,1,n) scanf("%d",&c[i]);
	rb(i,1,n-1) scanf("%d",&b[i]),b[i]+=b[i-1];
	rb(i,1,n-1) pre2[i]=pre2[i-1]+b[i];
	rl(i,n,1) pre2[i]=pre2[i-1];
	int l,r;
	int pro=1;
	rb(i,1,n) pro=1ll*pro*(c[i]+1)%MOD;
	l=INF,r=INF;
	rb(i,1,n) check_min(l,(0-pre2[i])/i),check_min(r,(10000-pre2[i])/i);
	rb(i,l,r) ans[i-l]=query(i);
	scanf("%d",&q);
	rb(i,1,q){
		int xi;
		scanf("%d",&xi);
		if(xi<=r&&xi>=l){
			printf("%d\n",ans[xi-l]);
		}
		else{
			if(xi>r){
				printf("0\n");
			}
			else{
				printf("%d\n",pro);
			}
		}
	}
	return 0;
}