#include<bits/stdc++.h>
#define For(i,a,b) for(register int i=(a);i<=(b);++i)
#define Rep(i,a,b) for(register int i=(a);i>=(b);--i)
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
	modint &operator +=(int o){return x=x+o>=mod?x+o-mod:x+o,*this;}
	modint &operator -=(int o){return x=x-o<0?x-o+mod:x-o,*this;}
	modint &operator *=(int o){return x=1ll*x*o%mod,*this;}
	modint &operator /=(int o){return *this *= ((modint(o))^=mod-2);}
	template<class I>friend modint operator +(modint a,I b){return a+=b;}
	template<class I>friend modint operator -(modint a,I b){return a-=b;}
	template<class I>friend modint operator *(modint a,I b){return a*=b;}
	template<class I>friend modint operator /(modint a,I b){return a/=b;}
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

#define maxn 400005
#define inf 0x3f3f3f3f

int n,m,a[maxn],sum[maxn],len,pos[maxn];
pii b[maxn];
int bo[maxn];
char s[maxn];

struct node{
	int c1,c2,cnt;
};
node operator +(node a,node b){
	if(!a.cnt)return b;
	if(!b.cnt)return a;
	if(a.c2!=b.c1)return (node){a.c1,b.c2,a.cnt+b.cnt};
	if(a.cnt==b.cnt)return (node){0,0,0};
	if(a.cnt<b.cnt)return (node){!a.c1,b.c2,b.cnt-a.cnt};
	return (node){a.c1,!b.c2,a.cnt-b.cnt};
}

node val[maxn<<2];
void build(int p,int l,int r){
	if(l==r){
		if((b[l].se-b[l].fi+1)&1) val[p]=(node){bo[l],bo[l],1};
		return;
	}
	int mid=l+r>>1;
	build(p<<1,l,mid);
	build(p<<1|1,mid+1,r);
	val[p]=val[p<<1]+val[p<<1|1];
}

node res;
void ask(int p,int l,int r,int ql,int qr){
	if(ql>qr)return;
	if(l>=ql&&r<=qr){
		res=res+val[p];
		return;
	}int mid=l+r>>1;
	if(ql<=mid)ask(p<<1,l,mid,ql,qr);
	if(qr>mid)ask(p<<1|1,mid+1,r,ql,qr);
}

signed main()
{
	n=read(),m=read();
	scanf("%s",s+1);
	For(i,1,n)a[i]=s[i]&1,a[i]^=(i%2==0);
//	For(i,1,n)cout<<a[i];puts(""); 
	For(l,1,n){
		int r=l;
		while(r<n&&a[r+1]==a[l])++r;
		b[++len]=mkp(l,r);
		bo[len]=a[l];
		For(j,l,r) pos[j]=len;
		l=r;
	}
	build(1,1,len);
	For(i,1,m){
		int l=read(),r=read();
		int xl=pos[l],xr=pos[r],sumd=xr-xl+1;
		if(xl==xr){
			puts("1");
			continue;
		}
		if(xl+1==xr){
			puts("2");
			continue;
		}
		res=(node){0,0,0};
		ask(1,1,len,xl+1,xr-1);
	//	cout<<"ask "<<xl+1<<' '<<xr-1<<endl;
		//  res.cnt  -=1
	//	if((r-b[xr].fi+1)&1)res=res+(node){bo[xr],bo[xr],1};
	//	if((b[xl].se-l+1)&1)res=(node){bo[xl],bo[xl],1}+res;
		// 
		int ans=0,del=0;
		int xia=0;
		if(res.cnt) xia=res.cnt-1+(bo[xl]!=res.c1)+(bo[xr]!=res.c2);
		else xia=(bo[xl]!=bo[xr]);
		int dxia=(xr-xl)-xia;
	//	cout<<"Dxia "<<dxia<<endl;
		ans+=dxia/2;
		ans+=xia+1;
		cout<<ans<<endl;
	}
	return 0;
}