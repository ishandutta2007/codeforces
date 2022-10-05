#include<bits/stdc++.h>
#define For(i,a,b) for(register int i=(a);i<=(b);++i)
#define Rep(i,a,b) for(register int i=(a);i>=(b);--i)
#define int long long
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

#define maxn 1500005
#define inf 0x3f3f3f3f

int n,m;
int x[maxn],p[maxn];
int t[maxn],l;
int a[maxn],b[maxn],c[maxn],b1[maxn]; 

void work()
{
	n=read(),m=read();
	l=0;
	For(i,1,n){
		x[i]=read(),p[i]=read();
		t[++l]=x[i]-p[i];
		t[++l]=x[i];
		t[++l]=x[i]+p[i];
//		a[x[i]-p[i]]++;
//		a[x[i]+1]-=2;
//		a[x[i]+p[i]+1]++;
	}
	sort(t+1,t+l+1),l=unique(t+1,t+l+1)-t-1;
	For(i,0,l+1)a[i]=b[i]=0;
	#define V(x) lower_bound(t+1,t+l+1,x)-t
	For(i,1,n){
		a[V(x[i]-p[i])]++;
		a[V(x[i])]-=2;
		a[V(x[i]+p[i])]++;
	}
	
	For(i,1,l)a[i]+=a[i-1];
	For(i,1,l)c[i]=c[i-1]+a[i-1]*(t[i]-t[i-1]);
//	For(i,1,l)cout<<t[i]<<' '<<c[i]<<endl;
	
	For(i,1,l)b[i]=max(0ll,c[i]-m); // need down
//	For(i,1,l)cout<<t[i]<<" "<<b[i]<<endl;
	For(i,2,l){
		b1[i]=b[i];
		if(b1[i-1])b1[i]=max(b1[i],b1[i-1]+t[i]-t[i-1]);
	}
	Rep(i,l-1,1){
		;
		if(b[i+1])b[i]=max(b[i],b[i+1]+t[i+1]-t[i]); 
	}
	For(i,1,l)b[i]=max(b[i],b1[i]);
	
//	For(i,1,l)cout<<t[i]<<" "<<b[i]<<endl;
	For(i,1,n){
		int ps=V(x[i]);
		if(b[ps]<=p[i])putchar('1');
		else putchar('0');
	}puts("");
}

signed main()
{
	int T=read();
	while(T--)work(); 
    return 0;
}

/*
4
3 6
1 5
5 5
3 4

2 3
1 3
5 2

2 5
1 6
10 6

6 12
4 5
1 6
12 5
5 5
9 7
8 3
*/