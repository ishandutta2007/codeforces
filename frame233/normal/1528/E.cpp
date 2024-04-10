#include<bits/stdc++.h>
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=1000005,mod=998244353,inv6=166374059;
typedef long long ll;
template<typename _Tp1,typename _Tp2>inline void add(_Tp1 &a,_Tp2 b){(a+=b)>=mod&&(a-=mod);}
template<typename _Tp1,typename _Tp2>inline void sub(_Tp1 &a,_Tp2 b){(a-=b)<0&&(a+=mod);}
int dp[N],s[N];
inline int calc3(int x){
	return (1ULL*x*(x-1)%mod*(x-2)%mod*inv6+1ULL*x*(x-1)+x)%mod;
}
inline int calc2(int x){
	return 1ULL*x*(x+1)/2%mod;
}
int main(){
	int n;read(n);
	dp[0]=1,s[0]=1;
	for(int i=1;i<=n;++i){
		dp[i]=dp[i-1];
		if(i>1)add(dp[i],1LL*dp[i-1]*s[i-2]%mod);
		add(dp[i],calc2(dp[i-1]));
		s[i]=s[i-1],add(s[i],dp[i]);
	}
	int ans=dp[n];
	add(ans,calc3(dp[n-1]));
	for(int i=0;i<n-1;++i)add(ans,1LL*dp[i]*calc2(dp[n-1])%mod);
	for(int i=0;i<n-1;++i)add(ans,1LL*dp[n-1]*calc2(dp[i])%mod);
	for(int i=1;i<n-1;++i)add(ans,1LL*dp[n-1]*dp[i]%mod*s[i-1]%mod);
	add(ans,ans),sub(ans,1);
	for(int i=1;i<n;++i)add(ans,1LL*(dp[i]-dp[i-1]+mod)*(dp[n-i-1]+mod-1)%mod);
	printf("%d\n",ans);
	return 0;
}