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
const int MAXN=5005;
const int MOD=998244353;
int sum[MAXN][MAXN],g[MAXN][MAXN],A[MAXN],B[MAXN],rfact[MAXN],fact[MAXN];
int quick(int A,int B){
	int ret=1;
	while(B){
		if(B&1) ret=1ll*ret*A%MOD;
		B>>=1;
		A=1ll*A*A%MOD;
	}
	return ret;
} 
int c(int A,int B){
	return 1ll*fact[A]*rfact[B]%MOD*rfact[A-B]%MOD;
}
LL solve(int n,int m,int ty){
	rb(d,1,n) rb(l,1,m) g[d][l]=1ll*sum[d-1][l]*c(n-d+l-1,n-d)%MOD;
	int ret=0;
	rb(l,1,m-1){
		rb(i,1,n) A[i]=g[i][l],B[i]=g[i][m-l];
		rb(i,1,n) (B[i]+=B[i-1])%=MOD;
		rb(i,1,n-ty-1){	
			(ret+=1ll*A[i]*B[n-ty-i]%MOD)%=MOD;
		}
	}
	(ret+=ret)%=MOD;
	return ret;
}
int main(){
	fact[0]=1;
	rb(i,1,5000) fact[i]=1ll*fact[i-1]*i%MOD;
	rfact[5000]=quick(fact[5000],MOD-2);
	rl(i,5000-1,0) rfact[i]=1ll*(i+1)*rfact[i+1]%MOD;
	int n,m;
	scanf("%d%d",&n,&m);
	int rest=0;
	rb(i,1,max(m,n)){
		sum[0][i]=1;
		rb(j,1,max(m,n)){
			sum[j][i]=(sum[j-1][i]+c(j+i-1,j))%MOD;
		}
	}
	rest=solve(n,m,0)+solve(m,n,1); 
	cout<<rest%MOD<<endl;
	return 0;
}