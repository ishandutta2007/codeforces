#include<bits/stdc++.h>
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int mod=1000000007;typedef long long ll;
template<typename _Tp1,typename _Tp2>inline void add(_Tp1 &a,_Tp2 b){a=a+b>=mod?a+b-mod:a+b;}
template<typename _Tp1,typename _Tp2>inline void sub(_Tp1 &a,_Tp2 b){a=a-b<0?a-b+mod:a-b;}
ll ksm(ll a,ll b=mod-2){ll res=1;while(b){if(b&1)res=res*a%mod;a=a*a%mod,b>>=1;}return res;}
int dp[105][13][16],cnt[16],y[105];
int main(){
	for(int i=0;i<16;++i)cnt[i]=cnt[i>>1]+(i&1);
	int n,K,m;read(n,K,m);dp[0][0][0]=1;
	for(int i=0;i<100;++i){
		for(int j=0;j<=K;++j){
			for(int st=0;st<1<<m;++st){
				add(dp[i+1][j][st>>1],dp[i][j][st]);
				if(j<K)add(dp[i+1][j+1][(st>>1)|(1<<(m-1))],1ULL*dp[i][j][st]*(cnt[st]+1)%mod);
			}
		}
	}
	for(int i=0;i<100;++i)for(int j=0;j<1<<m;++j)add(y[i],dp[i][K][j]);
	if(n<100)return printf("%d\n",y[n]),0;
	int ans=0;
	for(int i=50;i<100;++i){
		int A=1,B=1;
		for(int j=50;j<100;++j)if(i!=j)A=1LL*(n-j+mod)*A%mod,B=1LL*(i-j+mod)*B%mod;
		add(ans,1LL*y[i]*A%mod*ksm(B)%mod);
	}
	printf("%d\n",ans);
	return 0;
}