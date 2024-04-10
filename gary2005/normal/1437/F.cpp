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
const int MOD=998244353;
int n,a[5000+20];
LL quick(LL A,LL B){
	if(B==0) return 1;
	LL  tmp=quick(A,B>>1);
	tmp*=tmp;
	tmp%=MOD;
	if(B&1)
		tmp*=A,tmp%=MOD;
 	return tmp;
}
LL fact[5000+20],rfact[5000+20];
LL p(LL A,LL B){
	if(A<B) return 0;
	return fact[A]*rfact[A-B]%MOD;
}
LL dp[5000+20][5000+20];
int l[5000+20];
int main(){
	scanf("%d",&n);
	rb(i,1,n) scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	fact[0]=1ll;
	rb(i,1,n)
		fact[i]=fact[i-1]*i%MOD;
	rfact[n]=quick(fact[n],MOD-2);
	rl(i,n-1,0){
		rfact[i]=rfact[i+1]*(i+1)%MOD;
	}
	rb(i,1,n)
	{
		l[i]=l[i-1];
		while(2ll*a[l[i]+1]<=1ll*a[i]){
			l[i]++;
		}	
	}	
	rl(j,n-1,0){
		int suf=n+1;
		LL sum=0;
		rl(i,n,1){
			if(j==n-1){
				dp[i][j]=1;
				continue;
			}
			while(suf>1&&a[suf-1]>=a[i]*2){
				sum+=dp[--suf][j+1];
				sum%=MOD;
			}
			dp[i][j]=sum;
			if(j<l[i]){
				dp[i][j]+=dp[i][j+1]*(l[i]-j)%MOD;
				dp[i][j]%=MOD;
			}
		}	
	}
//	rb(i,1,n){
//		rb(j,0,n-1){
//			cout<<dp[i][j]<<' '; 
//		}
//		cout<<endl;
//	}
	LL rest=0;
	rb(i,1,n)
		rest+=dp[i][0],rest%=MOD;
	printf("%lld\n",rest);
	return 0;
}
/** 
  *  
	dp[i][j]=\sum dp[i'][j+1]+dp[i][j+1]*(l[i]-j)
  *
  **/