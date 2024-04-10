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
int n,c[MAXN],b[MAXN],q,x,dp[MAXN][MAXN*MAXN],pre2[MAXN];
int main(){
	scanf("%d",&n);
	rb(i,1,n) scanf("%d",&c[i]);
	rb(i,1,n-1) scanf("%d",&b[i]),b[i]+=b[i-1];
	rb(i,1,n-1) pre2[i]=pre2[i-1]+b[i];
	scanf("%d",&q);
	scanf("%d",&x);
	rl(i,n,1) pre2[i]=pre2[i-1]+i*x;
	dp[0][0]=1;
	rb(i,1,n) rb(j,0,100*100){
		if(dp[i-1][j]){
			rb(nx,0,c[i]){
				if(j+nx>=pre2[i]){
					(dp[i][j+nx]+=dp[i-1][j])%=MOD;
				}
			}
		}
	}
	int Ans=0;
	rb(j,0,100*100){
		(Ans+=dp[n][j])%=MOD;
	}
	cout<<Ans<<endl;
	return 0;
}