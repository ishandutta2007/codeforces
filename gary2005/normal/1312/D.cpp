/*
AuThOr GaRyMr
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
#define KEEP while(1)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define POB pop_back
#define ff fflush(stdout)
#define int LL
#define fastio ios::sync_with_stdio(false)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
int n,m;
const int MOD=998244353 ;
LL quick(int A,int B){
	if(B==0) return 1ll;
	LL tmp=quick(A,B>>1);
	tmp*=tmp;
	tmp%=MOD;
	if(B&1){
		tmp*=A;
		tmp%=MOD;
	}
	return tmp%MOD;
}
LL fact[200000+20];
LL inv(LL A){
	return quick(A,MOD-2);
}
LL c(int A,int B){
	return (((fact[A]*inv(fact[B]))%MOD)*inv(fact[A-B]))%MOD;
}
LL res=0;
signed main(){
	fastio;
	cin>>n>>m;
	if(n==2){
		cout<<0<<endl;
		return 0;
	}
	fact[0]=1;
	rb(i,1,200000)
		fact[i]=fact[i-1]*i,fact[i]%=MOD;
	LL qqq=quick(2,n-3);
	rb(i,1,m-1){
		int bigg,smll;
		bigg=m-i,smll=i-1;
		LL tmp=1;
		tmp*=c(bigg+smll,n-2);
//		cout<<tmp<<endl;
		tmp%=MOD;
//		cout<<tmp<<endl;
		if(smll>=n-2){
			tmp-=c(smll,n-2);
		}
//		cout<<tmp<<endl;
		tmp+=MOD;
		tmp%=MOD;
		tmp*=qqq;
		tmp%=MOD;
//		cout<<tmp<<endl;
		res+=tmp;
		res%=MOD;
	}
	cout<<res; 
	return 0;
}