#include<bits/stdc++.h>
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=(1<<16)+5,mod=998244353;
template<typename _Tp1,typename _Tp2>inline void add(_Tp1 &a,_Tp2 b){(a+=b)>=mod&&(a-=mod);}
template<typename _Tp1,typename _Tp2>inline void sub(_Tp1 &a,_Tp2 b){(a-=b)<0&&(a+=mod);}
typedef long long ll;
typedef unsigned long long ull;
ll ksm(ll a,ll b=mod-2){ll res=1;while(b){if(b&1)res=res*a%mod;a=a*a%mod,b>>=1;}return res;}
ll fac[18],inv[18],ifac[18];
int a[18],b[18],e[N][17],cnt[1<<16],f[N][17];
std::array<int,16> d[N];
int main(){
	for(int i=1;i<1<<16;++i)cnt[i]=cnt[i>>1]+(i&1);
	fac[0]=fac[1]=inv[0]=inv[1]=ifac[0]=ifac[1]=1;for(int i=2;i<18;++i)fac[i]=fac[i-1]*i%mod,inv[i]=inv[mod%i]*(mod-mod/i)%mod,ifac[i]=ifac[i-1]*inv[i]%mod;
	int n,k,c,s=0;read(n,k,c);
	for(int st=0;st<1<<k;++st){
		a[0]=1;for(int j=0;j<k;++j)a[j+1]=st>>j&1?mod-ifac[j+1]:ifac[j+1];
		b[0]=a[1];
		for(int i=1;i<k;++i){
			ull v=0;for(int j=0;j<i;++j)v+=1ULL*b[j]*a[i-j];
			b[i]=(1LL*(i+1)*a[i+1]+mod-v%mod)%mod;
		}
		for(int i=k-1;i>=0;--i)b[i+1]=1ULL*b[i]*inv[i+1]%mod;
		b[0]=0;for(int i=0;i<=k;++i)e[st][i]=b[i];
	}
	for(int i=1,x;i<=n;++i){
		read(x),s^=x;
		for(int j=0;j<k;++j)d[i][j]=x^(x-j-1);
	}
	std::sort(d+1,d+n+1);
	for(int i=1;i<=n;++i){
		int _=i;while(_<n&&d[_+1]==d[i])++_;
		for(int j=0;j<1<<c;++j){
			int st=0;for(int p=0;p<k;++p)st|=(cnt[d[i][p]&j]&1)<<p;
			for(int p=0;p<=k;++p)add(f[j][p],1LL*(_-i+1)*e[st][p]%mod);
		}
		i=_;
	}
	for(int st=0;st<1<<c;++st){
		for(int i=0;i<k;++i)a[i]=1ULL*(i+1)*f[st][i+1]%mod;
		b[0]=1;
		for(int i=0;i<k;++i){
			ull v=0;for(int j=0;j<=i;++j)v+=1ULL*b[j]*a[i-j];
			b[i+1]=1ULL*v%mod*inv[i+1]%mod;
		}
		for(int i=0;i<=k;++i)f[st][i]=b[i];
	}
	for(int len=1;len<1<<c;len<<=1)for(int i=0;i<1<<c;i+=len<<1)for(int j=0;j<len;++j)for(int d=0;d<=k;++d){int tmp=f[i+j+len][d];f[i+j+len][d]=f[i+j][d]-tmp<0?f[i+j][d]-tmp+mod:f[i+j][d]-tmp,add(f[i+j][d],tmp);}
	ll inv=(mod-((mod-1)>>c))*ksm(ksm(n),k)%mod;
	for(int i=0;i<1<<c;++i)printf("%lld%c",fac[k]*f[s^i][k]%mod*inv%mod," \n"[i+1==(1<<c)]);
	return 0;
}