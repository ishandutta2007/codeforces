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
#define int LL
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
const int MOD=998244353;
int my_pow(int x,int y){
	if(y==0){
		return 1;
	}
	int tmp=my_pow(x,y>>1);
	tmp*=tmp;
	tmp%=MOD;
	if(y&1){
		tmp*=x;
		tmp%=MOD;
	}
	return tmp;
}
int inv(int x){
	return my_pow(x,MOD-2);
}
int fact[1000000+1];
int c(int x,int y){
	return fact[y]*inv(fact[x])%MOD*inv(fact[y-x])%MOD;
}
signed main(){
	fastio;
	fact[0]=1;
	rb(i,1,1000000)
		fact[i]=fact[i-1]*i,fact[i]%=MOD;
	int n;
	cin>>n;
	LL res=fact[n];
	rb(i,1,n-1){
		res+=c(i,n)*fact[i]%MOD*(fact[n-i]-1)%MOD;
		res%=MOD;
	}
	cout<<res;
	return 0;
}