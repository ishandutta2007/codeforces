/*
AuThOr Gwj
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
#define debug_pair(A) cerr<<A.FIR<<" "<<A.SEC<<endl;
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
LL n,k;
const int MOD=998244353 ;
LL fact[1000000+2],invfact[1000000+2];
LL quick(LL A,LL B){
	if(!B) return 1ll;
	LL res=quick(A,B>>1);
	res*=res;
	res%=MOD;
	if(B&1)
	res*=A;
	return res%MOD;
}
LL c(int A,int B){
	return fact[B]*invfact[A]%MOD*invfact[B-A]%MOD;
}
int main(){
	fastio;
	fact[0]=invfact[0]=1;
	rb(i,1,1000000)
		fact[i]=fact[i-1]*i,fact[i]%=MOD;
	invfact[1000000]=quick(fact[1000000],MOD-2);
	rl(i,1000000,1)
		invfact[i-1]=invfact[i]*i,invfact[i-1]%=MOD;
	cin>>n>>k;
	LL res=0;
	for(int i=1;;i++){
//		if(i*k>n) break;
//		cout<<i<<endl;
		int can=n/i;
		if(can<k) break;
		res+=c(k-1,can-1);
		res%=MOD;
//		cout<<res<<endl;
	}
	cout<<res<<endl;
	return 0;
}