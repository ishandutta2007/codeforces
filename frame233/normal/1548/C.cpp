#include<bits/stdc++.h>
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
typedef long long ll;
const int N=3000005,mod=1000000007,inv2=(mod+1)/2;
ll ksm(ll a,ll b=mod-2){ll res=1;while(b){if(b&1)res=res*a%mod;a=a*a%mod,b>>=1;}return res;}
template<typename _Tp1,typename _Tp2>inline void add(_Tp1 &a,_Tp2 b){(a+=b)>=mod&&(a-=mod);}
template<typename _Tp1,typename _Tp2>inline void sub(_Tp1 &a,_Tp2 b){(a-=b)<0&&(a+=mod);}
struct num{
	ll a,b;
	inline num operator += (const num &o){return add(a,o.a),add(b,o.b),*this;}
	inline num operator + (const num &o)const{num x(*this);return x+=o;}
	inline num operator -= (const num &o){return sub(a,o.a),sub(b,o.b),*this;}
	inline num operator - (const num &o)const{num x(*this);return x-=o;}
	inline num operator * (const num &o)const{return {(1LL*a*o.a+1LL*(mod-3)*b%mod*o.b)%mod,(1LL*a*o.b+1LL*b*o.a)%mod};}
	inline num inv()const{
		ll o=ksm((1LL*a*a+3LL*b*b)%mod);
		return (num){a*o%mod,1LL*(mod-b)*o%mod};
	}
	inline num operator / (const num &o)const{return *this*(o.inv());}
};
ll fac[N],inv[N],ifac[N];
void init(){fac[0]=fac[1]=inv[0]=inv[1]=ifac[0]=ifac[1]=1;for(int i=2;i<N;++i)fac[i]=fac[i-1]*i%mod,inv[i]=inv[mod%i]*(mod-mod/i)%mod,ifac[i]=ifac[i-1]*inv[i]%mod;}
inline ll C(int n,int m){return n<m||m<0?0:fac[n]*ifac[m]%mod*ifac[n-m]%mod;}
num ksm(num a,int b){num res={1,0};while(b){if(b&1)res=res*a;a=a*a,b>>=1;}return res;}
num res[N];
int main(){
	init();
	int n,q;read(n,q),n*=3;
	num w[3];w[0]={1,0},w[1]={mod-inv2,inv2},w[2]=w[1]*w[1];
	for(int i=0;i<=n;++i)res[i]={C(n+1,i+1),0};
	for(int _=1;_<3;++_){
		num a=(num){1,0}-w[_],b=w[_],c=ksm(w[_],n+1),o=b/a,s={0,0},cur={1,0},qwq=a.inv();
		for(int i=0;i<=n;++i){
			s=s*o+(num){C(n+1,i),0};
			res[i]+=(cur-c*s)*qwq,cur=cur*o;
		}
	}
	ll inv3=ksm(3);
	while(q--){
		int x;read(x);
		printf("%lld\n",res[x].a*inv3%mod);
	}
	return 0;
}