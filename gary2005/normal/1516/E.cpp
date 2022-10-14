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
const int MOD=1e9+7;
int n,k;
int rest[202],c[404],dp[404][202],rfact[404],iv,fact[404];
int quick(int A,int B){
	if(B==0) return 1;
	int tmp=quick(A,B>>1);
	tmp=1ll*tmp*tmp%MOD;
	if(B&1) tmp=1ll*tmp*A%MOD;
	return tmp;
}
int inv(int A){return quick(A,MOD-2);}
int main(){
	scanf("%d%d",&n,&k);
	rb(i,0,min(n,400)){
		c[i]=1;
		rep(j,i){
			c[i]=1ll*c[i]*(n-j)%MOD;
		}
		rb(j,1,i){
			c[i]=1ll*c[i]*inv(j)%MOD;
		}
	}
	rfact[0]=1;
	rb(i,1,400) rfact[i]=1ll*rfact[i-1]*i%MOD;
	rb(i,0,400) fact[i]=rfact[i],rfact[i]=inv(rfact[i]);
	dp[0][0]=1;
	rb(i,2,k+1){
		iv=inv(i);
		rl(j,min(n,2*k),0){
			rl(l,k,0){
				if(dp[j][l]){
					int tmp=1;
					for(int pt=1;pt<=min((min(n,2*k)-j)/i,(k-l)/(i-1));++pt){
						tmp=1ll*tmp*iv%MOD;
						(dp[j+pt*i][l+pt*(i-1)]+=1ll*dp[j][l]*tmp%MOD*rfact[pt]%MOD)%=MOD;
					}
				}
			}
		}
	}
	rb(j,0,min(n,2*k)){
		rb(l,0,k){
			(rest[l]+=1ll*dp[j][l]*c[j]%MOD*fact[j]%MOD)%=MOD;
		}
	}
	rb(i,1,k){
		if(i>1) (rest[i]+=rest[i-2])%=MOD;
		printf("%d ",rest[i]);
	}
	return 0;
}