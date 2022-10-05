#include<bits/stdc++.h>
#define For(i,a,b) for(int i=(a);i<=(b);++i)
#define Rep(i,a,b) for(int i=(a);i>=(b);--i)
#define ll long long
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

#define maxn 200005
#define inf 0x3f3f3f3f3f3f3f3f

int n,r[maxn],g[maxn],t,d[maxn],c[maxn];
ll res,f[maxn];

int get(int x,int y){
	y=(y+c[x])%t;
	if(y<g[x])return 1;
	return t-y;
}
#define N maxn*100

int ls[N],rs[N],rt,tot,tag[N];

void down(int p){
	if(tag[p]){
		if(!ls[p])ls[p]=++tot;
		if(!rs[p])rs[p]=++tot;
		tag[ls[p]]=tag[rs[p]]=tag[p];
		tag[p]=0;
	}
}
void mdf(int&p,int l,int r,int ql,int qr,int x){
//	if(l==0&&r==t-1)cout<<"mdf "<<ql<<" "<<qr<<" "<<x<<endl;
	if(ql>qr)return;
	if(!p)p=++tot;
	if(l>=ql&&r<=qr){
		tag[p]=x;
//		cout<<"p: "<<l<<" "<<r<<" "<<x<<endl; 
		return;
	}
	int mid=l+r>>1;
	down(p);
	if(ql<=mid)mdf(ls[p],l,mid,ql,qr,x);
	if(qr>mid)mdf(rs[p],mid+1,r,ql,qr,x);
}
int ask(int&p,int l,int r,int x){
//	if(l==0&&r==t-1)cout<<"ask "<<x<<endl;
	if(!p)p=++tot;
//	cout<<"ask: "<<l<<' '<<r<<" "<<tag[p]<<endl;
	if(l==r)return tag[p];
	if(!ls[p])return tag[p];
	int mid=l+r>>1; down(p);
	if(x<=mid)return ask(ls[p],l,mid,x);
	return ask(rs[p],mid+1,r,x);
}
void dfs(int p,int l,int r){
	if(!p)return;
	if(tag[p]){
		if(tag[p]==n+1)res=0;
		else{
			res=min(res,f[tag[p]]+get(tag[p],l));
			res=min(res,f[tag[p]]+get(tag[p],r));
		}
		return;
	}
	int mid=l+r>>1;
	dfs(ls[p],l,mid);
	dfs(rs[p],mid+1,r);
}

void work()
{
	n=read(),t=read(); res=inf;
	For(i,1,n)
		g[i]=read(),c[i]=read(),r[i]=t-g[i];
	int sumd=0;
	For(i,1,n-1){
		d[i]=read();
		sumd=(sumd+d[i])%t;
		c[i+1]=(c[i+1]+sumd)%t;
	}
//	For(i,1,n-1)cout<<g[i]<<" "<<c[i]<<endl;
	rt=tot=1; tag[rt]=n+1;
	Rep(i,n,1){
		if(c[i]<=g[i])mdf(rt,0,t-1,g[i]-c[i],g[i]-c[i]+r[i]-1,i);
		else{
			int dt=c[i]-g[i];
			mdf(rt,0,t-1,t-dt,t-1,i);
			mdf(rt,0,t-1,0,r[i]-dt-1,i);
		}
		int nxt=ask(rt,0,t-1,(t-c[i])%t);
//		cout<<"nxt "<<nxt<<endl;
		if(nxt==n+1)f[i]=0;
		else f[i]=f[nxt]+get(nxt,(t-c[i])%t);
	}
//	For(i,1,n)cout<<f[i]<<" ";puts("");
	dfs(1,0,t-1);
	For(i,1,n-1)res+=d[i];
	cout<<res<<"\n";
}

signed main()
{
	int T=1;
	while(T--)work();
	return 0;
}

/*

*/