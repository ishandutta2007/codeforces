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
int a[300000+20];
LL fact[300000+20]; 
const int MOD=998244353;
LL quick(LL A,LL B){
	if(B==0) return 1;
	LL  tmp=quick(A,B>>1);
	tmp*=tmp;
	tmp%=MOD;
	if(B&1)
		tmp*=A,tmp%=MOD;
 	return tmp;
}
LL c(int A,int B){
	return fact[A]*quick(fact[B],MOD-2)%MOD*quick(fact[A-B],MOD-2)%MOD;
}
int main(){
	int n;
	scanf("%d",&n);
	rb(i,1,2*n){
		scanf("%d",&a[i]);
	}
	fact[0]=1ll;
	rb(i,1,2*n){
		fact[i]=fact[i-1]*i%MOD;
	}
	LL rest=0;
	sort(a+1,a+1+2*n);
	LL sum=0;
	rb(i,1,n)
		sum-=a[i];
	sum%=MOD;
	sum+=MOD;
	sum%=MOD;
	rest=sum*c(2*n,n)%MOD+MOD;
	rest%=MOD;
	rb(i,1,2*n){
		rest=(rest+1ll*a[i]*c(2*n-1,n-1)%MOD)%MOD;
	}
	cout<<rest*2%MOD<<endl;
	return 0;
}
/** 
  *
  *
  *
  *
  **/