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
#define debug_pair(A) cerr<<A.FIR<<" "<<A.SEC<<endl;
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
LL fact[200000+20],invfact[200000+20];
const int MOD=998244353 ;
LL quick(LL A,LL B){
	if(!B) return 1ll;
	LL k=quick(A,B>>1);
	k*=k;
	k%=MOD;
	if(B&1){
		k*=A;
		k%=MOD;
	}
	return k;
}
LL c(int x,int y){
	return fact[x]*invfact[y]%MOD*invfact[x-y]%MOD;
}
int main(){
	fastio;
	fact[0]=invfact[0]=1;
	rb(i,1,200000){
		fact[i]=fact[i-1]*i,fact[i]%=MOD;
	}	
	invfact[200000]=quick(fact[200000],MOD-2);
	rl(i,200000-1,1){
		invfact[i]=invfact[i+1]*(i+1),invfact[i]%=MOD;
	}
	int n;
	LL k;
	cin>>n>>k;
	if(k==0){
		cout<<fact[n]<<endl;
	}
	else
	if(k>=n){
		cout<<0<<endl;
	}
	else{
		k=n-k;
		LL ans=0;
		ans=quick(k,n)%MOD;
		bool is=1;
		rb(i,1,k-1){
			if(is){
				ans-=c(k,i)*quick((k-i),n)%MOD;
			}
			else{
				ans+=c(k,i)*quick((k-i),n)%MOD;
			}
			ans+=MOD;
			ans%=MOD;
			is^=1;
		}
		ans*=c(n,k);
		ans%=MOD;
		cout<<ans*2%MOD<<endl;
	}
	return 0;
}
/*
3 1
36

*/