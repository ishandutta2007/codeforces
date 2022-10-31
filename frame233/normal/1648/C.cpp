#include<bits/stdc++.h>
#define lowbit(x) ((x)&(-(x)))
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=200005,mod=998244353;typedef long long ll;
template<typename _Tp1,typename _Tp2>inline void add(_Tp1 &a,_Tp2 b){a=a+b>=mod?a+b-mod:a+b;}
template<typename _Tp1,typename _Tp2>inline void sub(_Tp1 &a,_Tp2 b){a=a-b<0?a-b+mod:a-b;}
ll fac[N],inv[N],ifac[N];
void init(){fac[0]=fac[1]=inv[0]=inv[1]=ifac[0]=ifac[1]=1;for(int i=2;i<N;++i)fac[i]=fac[i-1]*i%mod,inv[i]=inv[mod%i]*(mod-mod/i)%mod,ifac[i]=ifac[i-1]*inv[i]%mod;}
inline ll C(int n,int m){return n<m||m<0?0:fac[n]*ifac[m]%mod*ifac[n-m]%mod;}
int s[N],t[N],rest[N];
int c[N];void ADD(int x,int C){for(;x<N;x+=lowbit(x))add(c[x],C);}
int ask(int x){int ans=0;for(;x;x-=lowbit(x))add(ans,c[x]);return ans;}
int main(){
	init();
	int n,m;read(n,m);
	for(int i=1;i<=n;++i)read(s[i]),++rest[s[i]];
	for(int i=1;i<=m;++i)read(t[i]);
	int coef=1,ans=0;
	for(int i=1;i<=2e5;++i)ADD(i,rest[i]),coef=1LL*coef*ifac[rest[i]]%mod;
	for(int i=1;i<=m&&i<=n;++i){
		add(ans,1LL*ask(t[i]-1)*fac[n-i]%mod*coef%mod);
		ADD(t[i],mod-rest[t[i]]),coef=1LL*coef*rest[t[i]]%mod;
		if(--rest[t[i]]<0)break;
		ADD(t[i],rest[t[i]]);
	}
	if(*std::min_element(rest+1,rest+200001)>=0&&n<m)add(ans,1);
	printf("%d\n",ans);
	return 0;
}