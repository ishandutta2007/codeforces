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
#define fastio ios::sync_with_stdio(false)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
int n;
const int MOD=	 998244353;
LL my_pow(LL A,LL B){
	if(B==0) return 1;
	LL tmp=my_pow(A,B>>1);
	tmp*=tmp;
	tmp%=MOD;
	if(B&1) tmp*=A;
	return tmp%MOD;
}
LL inv(LL X){
	return my_pow(X,MOD-2);
}
LL p[200000+1];
int main(){
	fastio;
	cin>>n;
	LL B=1;
	rb(i,1,n)
		cin>>p[i],p[i]=p[i]*inv(100),p[i]%=MOD,B*=p[i],B%=MOD;
	LL sum=1;
	LL A=0;
	rb(i,1,n){
		A+=sum*inv(B)%MOD;
		A%=MOD;
		LL ai;
		ai=p[i];
		ai=ai%MOD;
		sum*=ai;
		sum%=MOD;
	}
	cout<<A<<endl;
	return 0;
}