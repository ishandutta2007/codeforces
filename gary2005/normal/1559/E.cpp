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
const int MAXN=51;
int n,m;
int l[MAXN],r[MAXN];
const int MAXM=1e5+1;
int mu[MAXM];
const int MOD=998244353;
void add(int & A,int B){
	A+=B;
	if(A>=MOD) A-=MOD;
}
int dp[MAXN][100000+1];
int main(){
	scanf("%d%d",&n,&m);
	rb(i,1,n) scanf("%d%d",&l[i],&r[i]);
	int ans=0;
	rb(i,1,1e5){
		int now=i;
		mu[i]=1;
		for(int j=2;j*j<=now;j++){
			if(now%j==0){
				if(now%(j*j)==0){
					mu[i]=0;
					break;
				}
				mu[i]*=-1;
				now/=j;
			}
		}
		if(now!=1) mu[i]*=-1;
		mu[i]=(mu[i]+MOD)%MOD;
	}
	dp[0][0]=1;
	rb(x,1,m){
		if(mu[x]){
			int M=m/x;
			rb(i,1,n) rb(j,1,M) dp[i][j]=0;
			rb(i,1,n){
				int l_,r_;
				l_=(l[i]+x-1)/x;
				r_=(r[i])/x;
				if(l_<=r_){
					int sum=0;
					rb(j,l_,M){
						add(sum,dp[i-1][j-l_]);
						dp[i][j]=sum;
						if(j>=r_)
						add(sum,MOD-dp[i-1][j-r_]);
					}
				}
			}
			int sum=0;
			rb(j,1,M) add(sum,dp[n][j]);
			add(ans,1ll*sum*mu[x]%MOD);
		}
	}
	cout<<ans<<endl;
	return 0;
}