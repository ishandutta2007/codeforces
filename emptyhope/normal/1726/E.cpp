#include<bits/stdc++.h>
#define For(i,a,b) for(int i=(a);i<=(b);++i)
#define Rep(i,a,b) for(int i=(a);i>=(b);--i)
//#define int long long
using namespace std;
inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

// modint
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

#define maxn 300005
#define inf 0x3f3f3f3f

int n;
modint f[maxn],w[maxn],mul[maxn];
void work()
{
	n=read();
	modint res=0;
	For(i,0,n/4){
		int rest=n-i*4;
		res+=w[rest]*mul[i*2]*qpow(2,i)*C(rest+i*2,i*2);
//		cout<<res.x<<endl;
	}
	cout<<res.x<<"\n";
}

signed main()
{
	mul[0]=mul[2]=1;
	for(int i=4;i<=300000;i+=2)
		mul[i]=mul[i-2]*(i-1);
	w[0]=w[1]=1;
	For(i,2,300000){
		w[i]=w[i-2]*(i-1)+w[i-1];
	}
//	n=read();
//	For(i,1,n)p[i]=i;
//	do{
//		For(i,1,n)q[p[i]]=i;
//		bool bo=1;
//		For(i,1,n)if(abs(p[i]-q[i])>1)bo=0;
//		if(bo){
//			For(i,1,n)vis[i]=0;
//			For(i,1,n)if(!vis[i]){
//				int u=i;
//				while(!vis[u])cout<<u<<" ",vis[u]=1,u=p[u];
//				cout<<" || ";
//			}puts("");
//		}
//	}while(next_permutation(p+1,p+n+1));
	int T=read();
	while(T--)work();
	return 0;
}

/*

*/