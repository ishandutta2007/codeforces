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
const int MAXN=3e6+10;
const int MOD=1e9+7;
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
int fact[MAXN+1],ifact[MAXN+1];
int n,q;
int c(int A,int B){
	return 1ll*fact[A]*ifact[B]%MOD*ifact[A-B]%MOD;
}
vector<int> getf(int k){
	// (1+x)^k
	vector<int> f(k+1);
	rb(i,0,k) f[i]=c(k,i);
	return f;
}
vector<int> long_div(vector<int> A,vector<int> B){
	vector<int> Ans(A.size()-B.size()+1);
	int N,M;
	N=A.size()-1;
	M=B.size()-1;
	int iv=inv(B[M]);
	rl(i,N,M){
		Ans[i-M]=1ll*A[i]*iv%MOD;
		rb(j,0,M){
			A[i-M+j]+=MOD-1ll*B[j]*Ans[i-M]%MOD;
			A[i-M+j]%=MOD;
		}
	}
	return Ans;
}
int main(){
	fact[0]=1;
	rb(i,1,MAXN) fact[i]=1ll*fact[i-1]*i%MOD;
	ifact[MAXN]=inv(fact[MAXN]);
	rl(i,MAXN-1,0) ifact[i]=1ll*ifact[i+1]*(i+1)%MOD;
	scanf("%d%d",&n,&q);
	vector<int> A,B;
	A=getf(3*n+3);
	B=getf(3);
	rb(i,0,3) (A[i]+=MOD-B[i])%=MOD;
	B[0]=0;
	vector<int> Ans=long_div(A,B);
	rb(i,1,q){
		int x;
		scanf("%d",&x);
		printf("%d\n",Ans[x]);
	}
	return 0;
}