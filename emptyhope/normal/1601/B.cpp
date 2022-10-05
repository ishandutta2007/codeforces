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

#define maxn 300005
#define inf 0x3f3f3f3f

int n,a[maxn],b[maxn],cnt,rt;

struct edge{
	int to,nxt,w;
}e[maxn*40];
int tot,head[maxn*8];
void add(int u,int v,int w){
//	cout<<"add "<<u<<' '<<v<<' '<<w<<endl;
	e[++tot]=(edge){v,head[u],w};
	head[u]=tot;
}

int ls[maxn*8],rs[maxn*8];
void build(int &p,int l,int r){
	p=++cnt;
//	cout<<p<<" "<<l<<" "<<r<<endl;
	if(l==r){
		add(p,l+n,0);
		return;
	}
	int mid=l+r>>1;
	build(ls[p],l,mid),build(rs[p],mid+1,r);
	add(p,ls[p],0),add(p,rs[p],0);
}
void ins(int p,int l,int r,int nl,int nr,int u){
	if(l>=nl&&r<=nr)return add(u,p,1);
	int mid=l+r>>1;
	if(nl<=mid)ins(ls[p],l,mid,nl,nr,u);
	if(nr>mid)ins(rs[p],mid+1,r,nl,nr,u); 
}

int dis[maxn*8],lst[maxn*8];
bool vis[maxn*8];
int q[maxn*16],h,t;
void bfs(int u)
{
	memset(dis,63,sizeof dis); dis[u]=0;
	q[h=t=maxn*8]=u;
	while(h<=t){
		int u=q[h];++h;
		if(vis[u])continue;
		vis[u]=1;
	//	cout<<u<<" "<<h<<" "<<t<<endl;
		for(int i=head[u];i;i=e[i].nxt){
			int v=e[i].to,w=e[i].w;
			if(!vis[v] && dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				lst[v]=u;
				if(!w)--h,q[h]=v;
				else q[++t]=v;
			}
		}
	}
}

void work()
{
	n=read();cnt=n*2;
	For(i,1,n)a[i]=read();
	For(i,1,n)b[i]=read();
	build(rt,1,n);
	For(i,1,n){
		if(a[i]==i) add(i,0,1);
		else ins(rt,1,n,i-a[i],i,i);
		add(i+n,i+b[i],0);
	}//puts("donw");
	bfs(n);//puts("qwq");
	if(dis[0]==inf) puts("-1");
	else{
		vi o;
		int u=0; o.pb(0);
		while(u!=n){
			u=lst[u];
			o.pb(u);
		}
		o.pop_back();
		reverse(o.begin(),o.end());
		cout<<dis[0]<<endl;
		for(auto t:o)if(t>=n+1&&t<=n+n)cout<<t-n<<' ';cout<<0;
		puts("");
	}
}

signed main()
{
//	freopen("data.in","r",stdin);
	work();
	return 0;
}