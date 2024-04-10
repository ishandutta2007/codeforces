#include<bits/stdc++.h>
#define For(i,a,b) for(register int i=(a);i<=(b);++i)
#define Rep(i,a,b) for(register int i=(a);i>=(b);--i)
//#define int long long
#define ll long long
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
#define mkp make_pair
#define pb push_back
typedef pair<int,int>pii;
typedef vector<int>vi;

#define maxn 200005
#define inf 0x3f3f3f3f

int l,a[maxn];
char s[maxn];

modint f[maxn][2][2][2][2][2][2];

int orz[8]={0,1,2,3,3,2,1,0};

signed main()
{
	cin>>s+1;l=strlen(s+1);
	For(i,1,l)a[i]=(s[i]&1);
	
	f[0][0][0][0][0][0][0]=1;
	For(i,0,l-1){
		int c=a[i+1];
	//	cout<<"c: "<<c<<endl;
		For(i0,0,1)For(j0,0,1)For(k0,0,1)
			For(i1,0,1)For(j1,0,1)For(k1,0,1){
				modint val=f[i][i0][j0][k0][i1][j1][k1];
				if(!val.x)continue;
				For(i2,0,(i0?1:c))For(j2,0,(j0?1:c))For(k2,0,(k0?1:c)){
					int sta=(i2*4+j2*2+k2);
					sta=orz[sta];
					f[i+1][i0|(i2<c)][j0|(j2<c)][k0|(k2<c)][i1|(sta==1)][j1|(sta==2)][k1|(sta==3)]+=val;
				}
			}
	}
	
	modint res=0;
	For(i,0,1)For(j,0,1)For(k,0,1)res+=f[l][i][j][k][1][1][1];
	cout<<res.x;
    return 0;
}