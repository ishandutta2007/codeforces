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
const int MOD=1e9+7;
const int MAXN=3e5+233;
int fact[MAXN],ifact[MAXN],tot[MAXN],dp[MAXN];
int quick(int A,int B){
	if(B==0) return 1;
	int tmp=quick(A,B>>1);
	tmp=1ll*tmp*tmp%MOD;
	if(B&1) tmp=1ll*tmp*A%MOD;
	return tmp;
}
int inv(int A){return quick(A,MOD-2);}
int C(int A,int B){
	return 1ll*fact[A]*ifact[B]%MOD*ifact[A-B]%MOD;
}
void solve(){
	int n,k;
	scanf("%d%d",&n,&k);
	int sum=0;
	dp[0]=1;
	rb(i,1,n){
		(sum+=dp[i-1])%=MOD;
		if(i>=k){
			(sum+=MOD-dp[i-k])%=MOD;
		}
		dp[i]=sum;
	}
	int ans=1;
	rb(z,2,n/k+5){
		int len=(z-1)*(k-1)+z;
		if(len>n) continue;
//		cout<<z<<' '<<C(n-len+z,z)<<endl;
		(ans+=1ll*C(n-len+z,z)%MOD*ifact[n]%MOD*fact[n-z]%MOD*fact[z]%MOD)%=MOD;
	}
	printf("%d\n",ans+1);
}
int main(){
	fact[0]=1;
	rb(i,1,300000) fact[i]=1ll*i*fact[i-1]%MOD;
	rb(i,0,300000) ifact[i]=inv(fact[i]);
	int t;
	scanf("%d",&t);
	while(t--) solve();
	return 0;
}