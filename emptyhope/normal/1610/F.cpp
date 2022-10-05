#include<bits/stdc++.h>
#define For(i,a,b) for(register int i=(a);i<=(b);++i)
#define Rep(i,a,b) for(register int i=(a);i>=(b);--i)
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

#define maxn 600005
#define inf 0x3f3f3f3f

int n,m,res;
struct edge{
	int to,nxt,w,ans;
}e[maxn<<2];
int tot=1,head[maxn],nxt[maxn];
int now[maxn][3];
inline void adde(int u,int v,int w){
	e[++tot]=(edge){v,head[u],w,-1};
	nxt[tot]=now[u][w];
	now[u][w]=head[u]=tot;
}
int a[maxn],deg[maxn];

void dfs(int u,int c)
{
	while(now[u][c] && e[now[u][c]].ans!=-1)
		now[u][c]=nxt[now[u][c]];
	if(!now[u][c]){
		c=(c==1?2:1);
		while(now[u][c] && e[now[u][c]].ans!=-1)
			now[u][c]=nxt[now[u][c]];
	}
	if(!now[u][c])return;
	e[now[u][c]].ans=1;
	e[now[u][c]^1].ans=2;
	int t=now[u][c];
	now[u][c]=nxt[now[u][c]];
	dfs(e[t].to,c);
	for(int i=head[u];i;i=e[i].nxt){
		head[u]=e[i].nxt;
		if(e[i].ans==-1)
			e[i].ans=1,e[i^1].ans=2,dfs(e[i].to,e[i].w);
	}
}

signed main()
{
	n=read(),m=read();
	For(i,1,m){
		int u=read(),v=read(),w=read();
		adde(u,v,w),adde(v,u,w);
		a[u]+=w,a[v]+=w;
		++deg[u],++deg[v];
	}
	For(i,1,n)
		if(a[i]&1) ++res;
	For(i,1,n)
		if(deg[i]&1) adde(n+1,i,1),adde(i,n+1,1);
	cout<<res<<endl;
	For(i,1,n)
		if(head[i]) dfs(i,1);
	For(i,1,m)
		cout<<e[i*2].ans;
	return 0;
}