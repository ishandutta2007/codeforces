// what is matter? never mind. 
#include<bits/stdc++.h>
#define For(i,a,b) for(int i=(a);i<=(b);++i)
#define Rep(i,a,b) for(int i=(a);i>=(b);--i)
#define int long long
using namespace std;
inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

#define mod 998244353
struct modint{
	int x;
	modint(int o=0){x=o;}
	modint &operator = (int o){return x=o,*this;}
	modint &operator +=(modint o){return x=x+o.x>=mod?x+o.x-mod:x+o.x,*this;}
	modint &operator -=(modint o){return x=x-o.x<0?x-o.x+mod:x-o.x,*this;}
	modint &operator *=(modint o){return x=1ll*x*o.x%mod,*this;}
	modint &operator ^=(int b){
		modint a=*this,c=1;
		for(;b;b>>=1,a*=a)if(b&1)c*=a;
		return x=c.x,*this;
	}
	modint &operator /=(modint o){return *this *=o^=mod-2;}
	friend modint operator +(modint a,modint b){return a+=b;}
	friend modint operator -(modint a,modint b){return a-=b;}
	friend modint operator *(modint a,modint b){return a*=b;}
	friend modint operator /(modint a,modint b){return a/=b;}
	friend modint operator ^(modint a,int b){return a^=b;}
	friend bool operator ==(modint a,int b){return a.x==b;}
	friend bool operator !=(modint a,int b){return a.x!=b;}
	bool operator ! () {return !x;}
	modint operator - () {return x?mod-x:0;}
	bool operator <(const modint&b)const{return x<b.x;}
};
inline modint qpow(modint x,int y){return x^y;}
 
vector<modint> fac,ifac,iv;
inline void initC(int n)
{
	if(iv.empty())fac=ifac=iv=vector<modint>(2,1);
	int m=iv.size(); ++n;
	if(m>=n)return;
	iv.resize(n),fac.resize(n),ifac.resize(n);
	For(i,m,n-1){
		iv[i]=iv[mod%i]*(mod-mod/i);
		fac[i]=fac[i-1]*i,ifac[i]=ifac[i-1]*iv[i];
	}
}
inline modint C(int n,int m){
	if(m<0||n<m)return 0;
	return initC(n),fac[n]*ifac[m]*ifac[n-m];
}
inline modint sign(int n){return (n&1)?(mod-1):(1);}

#define fi first
#define se second
#define pb push_back
#define mkp make_pair
typedef pair<int,int>pii;
typedef vector<int>vi;

#define maxn 200005 
#define inf 0x3f3f3f3f

int l,r;

int GET(int x){
	int l=1,r=inf,res=0;
	while(l<=r){
		int mid=l+r>>1;
		if(mid*mid<=x)res=mid,l=mid+1;
		else r=mid-1;
	}return res;
}

int calc(int x){
	if(!x)return 0;
	if(x<=20){
		int res=0;
		For(i,1,x){
			int j=floor(sqrt(i));
			if(i%j==0)++res;
		}return res;
	}
	int y=GET(x-1);
	++y;
	int res=0;
	res+=(y-1)*3-2;
	if(y*y<=x)++res;
	if(y*y-1<=x)++res;
	if(y*(y-1)<=x)++res;
	return res; 
}
void work()
{
	l=read(),r=read();
	cout<<calc(r)-calc(l-1)<<"\n";
}

signed main()
{
//	For(i,1,100){
//		int j=floor(sqrt(i));
//		if(i%j==0)cout<<i<<"\n";
//	}
//	For(i,1,100)if(calc(i)!=calc(i-1))cout<<i<<'\n';
	int T=read();
	while(T--)work(); 
	return 0;
}