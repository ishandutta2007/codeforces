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

#define mod 1000000007
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
};

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

#define maxn 2000005
#define inf 0x3f3f3f3f

int n,m,a[maxn],b[maxn],t[maxn];
pii c[maxn];
long long res;

int val[maxn<<2],tag[maxn<<2];
void clear(int p,int l,int r){
	tag[p]=val[p]=0;
	if(l==r)return;
	int mid=l+r>>1;
	clear(p<<1,l,mid),clear(p<<1|1,mid+1,r);
}
inline void up(int p){
	val[p]=min(val[p<<1],val[p<<1|1]);
}
inline void pt(int p,int v){
	tag[p]+=v;
	val[p]+=v;
}
inline void pd(int p){
	if(tag[p])
		pt(p<<1,tag[p]),pt(p<<1|1,tag[p]),tag[p]=0;
}
void mdf(int p,int l,int r,int nl,int nr,int v){
	if(nl>nr)return;
	if(l>=nl&&r<=nr)return pt(p,v);
	int mid=l+r>>1; pd(p);
	if(nl<=mid)mdf(p<<1,l,mid,nl,nr,v);
	if(nr>mid)mdf(p<<1|1,mid+1,r,nl,nr,v);
	up(p); 
}

int tr[maxn];
void add(int x,int y){
	for(;x<=n;x+=x&-x)tr[x]+=y;
}
inline int ask(int x){
	int res=0;
	for(;x;x^=x&-x)res+=tr[x];
	return res;
}

void work()
{
	n=read(),m=read();res=0;
	For(i,1,n)a[i]=read(),c[i]=mkp(a[i],i),t[i]=a[i];
	For(i,1,m)b[i]=read(),c[i+n]=mkp(b[i],n+1);
	sort(t+1,t+n+1);
	For(i,1,n)a[i]=lower_bound(t+1,t+n+1,a[i])-t;
	For(i,1,n){
		res+=i-1-ask(a[i]);
		add(a[i],1);
	}//cout<<"res: "<<res<<endl; 
	For(i,1,n)tr[i]=0;
	sort(c+1,c+n+m+1);
	clear(1,1,n+1);
	For(i,1,n) mdf(1,1,n+1,i+1,n+1,1); 
//	cout<<"val "<<val[1]<<endl;
//	For(i,1,n*2){
//		cout<<c[i].fi<<" "<<c[i].se<<endl;
//	}
	For(i,1,n+m){
		int j=i;
		while(j+1<=n+m && c[j+1].fi == c[i].fi) ++j;
		For(p,i,j){
			if(c[p].se<=n) mdf(1,1,n+1,c[p].se+1,n+1,-1);//cout<<"add "<<c[p].se+1<<' '<<n+1<<' '<<-1<<endl;
			else res+=val[1];
		}
		For(p,i,j)
			if(c[p].se<=n) mdf(1,1,n+1,1,c[p].se,1);//cout<<"add "<<1<<" "<<c[p].se<<' '<<1<<endl;
		i=j;
	}
	printf("%lld\n",res);
}

signed main()
{
	int T=read();
	while(T--)work(); 
	return 0;
}