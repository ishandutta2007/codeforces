#include<bits/stdc++.h>
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=10000005,mod=998244353;typedef long long ll;
template<typename _Tp1,typename _Tp2>inline void add(_Tp1 &a,_Tp2 b){a=a+b>=mod?a+b-mod:a+b;}
template<typename _Tp1,typename _Tp2>inline void sub(_Tp1 &a,_Tp2 b){a=a-b<0?a-b+mod:a-b;}
ll ksm(ll a,ll b=mod-2){ll res=1;while(b){if(b&1)res=res*a%mod;a=a*a%mod,b>>=1;}return res;}
int pw[N],a[N];
void init(){
	pw[0]=1;for(int i=1;i<N;++i)pw[i]=pw[i-1],add(pw[i],pw[i-1]);
	int mul=1;for(int i=1;i<N;++i)mul=1ULL*mul*(pw[i]-1)%mod;
	a[N-1]=ksm(mul);for(int i=N-2;i>=1;--i)a[i]=1ULL*a[i+1]*(pw[i+1]-1)%mod;
}
void MAIN(){
	int n,k,x;read(n,k,x);
	if(!x){
		if(n>k)return puts("0"),void();
		int ans=1;for(int i=0;i<n;++i)ans=1LL*ans*(pw[k]-pw[i]+mod)%mod;
		printf("%d\n",ans);return;
	}
	int ans=pw[k]-1,cur=1,qwq=ksm(2,n),iq=ksm(2);
	for(int i=1,coef=pw[k]-1;i<k;++i){
		cur=1ULL*cur*(qwq-1)%mod,qwq=1ULL*qwq*iq%mod,coef=1ULL*coef*(pw[k]-pw[i]+mod)%mod;
		add(ans,1ULL*coef*cur%mod*a[i]%mod);
	}
	printf("%lld\n",ksm(pw[k]-1)*ans%mod);
}
int main(){
	init();int _;read(_);
	while(_--)MAIN();
	return 0;
}