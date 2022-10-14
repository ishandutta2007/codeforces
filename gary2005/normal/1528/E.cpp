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
const int MOD=998244353;
const int MAXN=1e6+1;
int dp[MAXN],s[MAXN];
int g(int a,int b){
	if(b==0)  return (a==0);
	if(a==0) return b==0;
	if(a==1) return dp[b-1];
	if(a==2) return (MOD+dp[b]-dp[b-1])%MOD;
	int ans=0;
	int A=dp[b-1];
	ans=1ll*A*(A-1)%MOD*(A-2)%MOD*166374059ll%MOD;
	(ans+=1ll*A*(A-1)%MOD)%=MOD;
	(ans+=A)%=MOD;
	if(b>=2){
		(ans+=1ll*A*(A+1)/2%MOD*s[b-1]%MOD)%=MOD;
		(ans+=1ll*(s[b-1])*(s[b-1]+1)/2%MOD*A%MOD)%=MOD;
	}
	return ans;
}
int solve(int n){
	int ans=0;
	rep(i,4)
		rep(j,4){
			if(i+j<=3&&(i>=2||i==0)){
				rb(x,0,n){
//					if(g(i,x)*g(j,n-x)%MOD)
//					cout<<i<<" "<<j<<" "<<x<<" "<<g(i,x)*g(j,n-x)%MOD<<endl;
					int tmp=1ll*g(i,x)*g(j,n-x)%MOD;
					(ans+=tmp)%=MOD;
				}
			}
		}
	return ans;
}
int main(){
	int n;
	scanf("%d",&n);
	dp[0]=1;
	int sum=0;
	rb(i,1,n) (dp[i]=1ll*dp[i-1]*sum%MOD+1ll*dp[i-1]*(dp[i-1]+1)/2%MOD)%=MOD,(dp[i]+=dp[i-1])%=MOD,(sum+=dp[i-1])%=MOD,s[i]=sum;
	printf("%d\n",solve(n));
	return 0;
}