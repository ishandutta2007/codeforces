/*
{
######################
#       Author       #
#        Gary        #
#        2020        #
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
int t;
const int MOD=1e9+7;
int cnt[60],n,val[500000+20];
LL x[500000+20];
int sum[60];
void solve()
{
	scanf("%d",&n);
	memset(cnt,0,sizeof(cnt));
	memset(sum,0,sizeof(sum));
	rb(i,1,n){
		val[i]=0;
		scanf("%lld",&x[i]);
		rep(j,60){
			if((x[i]>>j)&1) cnt[j]++;
		}
	}
	rb(i,1,n){
		rep(j,60){
			LL is=1ll<<j;
			is%=MOD;
			if((x[i]>>j)&1){
				(val[i]+=is*n%MOD)%=MOD;
			}
			else{
				(val[i]+=is*cnt[j]%MOD)%=MOD;
			}
		}
		rep(j,60){
			if((x[i]>>j)&1){
				(sum[j]+=val[i])%=MOD;
			}
		}
	}
	LL rest=0;
	rep(j,60){
		LL is=1ll<<j;
		is%=MOD;
		is=is*cnt[j]%MOD;
		is=is*sum[j]%MOD;
		rest+=is;
		rest%=MOD;
	}
	printf("%lld\n",rest);
}
int main(){
	scanf("%d",&t);
	rb(i,1,t) solve();	
	return 0;
}