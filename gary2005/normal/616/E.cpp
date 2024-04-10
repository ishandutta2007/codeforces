/*
{
######################
#       Author       #
#        Gary        #
#        2020        #
######################
*/
#include<bits/stdc++.h>
#define int LL
#define rb(a,b,c) for(LL a=b;a<=c;++a)
#define rl(a,b,c) for(LL a=b;a>=c;--a)
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
LL n,m;
const int MOD=1e9+7;
LL get(LL l,LL r){
	LL A,B;
	A=l+r;
	B=r-l+1;
	if(A&1) B>>=1;
	else A>>=1;
	A%=MOD;
	B%=MOD;
	return A*B%MOD;
}
signed main(){
	cin>>n>>m;
	LL rest=(n%MOD)*(m%MOD)%MOD;
	check_min(m,n);
	LL minu=0;
	rb(i,1,10000000){
		(minu+=1ll*get(min(n/(i+1),m)+1,min(n/i,m))*i%MOD)%=MOD;
	}
	rb(i,1,min(m,n/10000001)){// n/i > 1e7
		assert(n/i>1e7);
		(minu+=n/i%MOD*i%MOD)%=MOD;
	}
	rest-=minu;
	rest+=MOD;
	rest%=MOD;
	cout<<rest<<endl;
	return 0;
}