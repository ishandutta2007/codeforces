#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
typedef long long ll;
constexpr int N=1e6+5,mod=1e9+7,iv2=mod+1>>1;
int T,n,pw2[N],inv2[N],dp[N],s[N];
inline void rd(int &x){
    x=0;int f=1;char c;while(!isdigit(c=getchar()))if(c=='-')f=-f;
    do x=x*10+(48^c);while(isdigit(c=getchar()));x*=f;
}
int main(){
	rd(T),pw2[0]=inv2[0]=1;
	rep(i,1,1e6){
		pw2[i]=(pw2[i-1]+pw2[i-1])%mod;
		inv2[i]=(ll)inv2[i-1]*iv2%mod;
	}
	while(T--){
		rd(n);
		dp[n]=1,s[n]=inv2[n-1],s[n+1]=0;
		per(i,n-1,1){
			int lim=min(n,i+i-1);
			dp[i]=(ll)(s[i+1]-s[lim+1]+mod)*pw2[i]%mod;
			s[i]=(s[i+1]+(ll)dp[i]*inv2[i])%mod;
		}
		rep(i,1,n-1)
			printf("%d\n",(ll)inv2[i+1>>1]*dp[i]%mod);
		printf("%d\n",(ll)inv2[n-1>>1]*dp[n]%mod);
	}
	return 0;
}