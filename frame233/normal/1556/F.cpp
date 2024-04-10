#include<bits/stdc++.h>
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=14,mod=1000000007;
typedef long long ll;
template<typename _Tp1,typename _Tp2>inline void add(_Tp1 &a,_Tp2 b){(a+=b)>=mod&&(a-=mod);}
template<typename _Tp1,typename _Tp2>inline void sub(_Tp1 &a,_Tp2 b){(a-=b)<0&&(a+=mod);}
ll ksm(ll a,ll b=mod-2){ll res=1;while(b){if(b&1)res=res*a%mod;a=a*a%mod,b>>=1;}return res;}
int win[N][N],a[N],dp[1<<N],p[N][1<<N],cnt[1<<N];
int main(){
	for(int i=0;i<1<<N;++i)cnt[i]=cnt[i>>1]+(i&1);
	int n;read(n);
	for(int i=0;i<n;++i)read(a[i]);
	for(int i=0;i<n;++i)for(int j=0;j<n;++j)if(i!=j)win[i][j]=1LL*a[i]*ksm(a[i]+a[j])%mod;
	for(int i=0;i<n;++i){
		for(int j=0;j<1<<n;++j)if(!(j>>i&1)){
			p[i][j]=1;
			for(int k=0;k<n;++k)if(j>>k&1)p[i][j]=1LL*p[i][j]*win[i][k]%mod;
		}
	}
	int ans=0;
	for(int x=0;x<n;++x){
		memset(dp,0,sizeof(dp));
		for(int st=1;st<1<<n;++st)if(st>>x&1){
			dp[st]=1;
			for(int s=(st-1);s;s=(s-1)&st)if(s>>x&1){
				int coef=dp[s];
				for(int j=0;j<n;++j)if((st^s)>>j&1)coef=1LL*coef*p[j][s]%mod;
				sub(dp[st],coef);
			}
		}
		add(ans,dp[(1<<n)-1]);
	}
	printf("%d\n",ans);
	return 0;
}