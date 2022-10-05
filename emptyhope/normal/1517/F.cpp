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

#define fi first
#define se second
#define pb push_back
#define mkp make_pair
typedef pair<int,int>pii;
typedef vector<int>vi;

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

#define maxn 303
int n;
vector<int>e[maxn];
modint res,f[maxn][maxn],g[maxn][maxn];
modint lst,tf[maxn],tg[maxn];
int len[maxn];
void dfs(int u,int pa,int r)
{
	f[u][0]=g[u][0]=1,len[u]=0;
	for(auto v:e[u])
	{
		if(v==pa)continue;
		dfs(v,u,r);
		For(i,0,max(len[u],len[v]+1))tf[i]=tg[i]=0;
		For(i,0,len[u])
			For(j,0,len[v]){
				tf[min(i,j+1)]+=f[u][i]*f[v][j];
				tg[max(i,j+1)]+=g[u][i]*g[v][j];
				if(i+j+1<=r){
					tf[i]+=f[u][i]*g[v][j];
					tf[j+1]+=g[u][i]*f[v][j];
				}
				else{
					tg[j+1]+=f[u][i]*g[v][j];
					tg[i]+=g[u][i]*f[v][j];
				}
			}
		len[u]=max(len[u],len[v]+1);
		For(i,0,len[u]) f[u][i]=tf[i],g[u][i]=tg[i];
	}
}
void solve(int x)
{
	memset(f,0,sizeof f);
	memset(g,0,sizeof g);
	dfs(1,0,x);
	modint qwq=0;
	For(i,0,n)qwq+=f[1][i];
	res+=(qwq-lst)*(x-1); lst=qwq; 
//	cout<<x<<" "<<lst.x<<endl;
}

signed main()
{
	n=read();
	For(i,2,n){
		int u=read(),v=read();
		e[u].pb(v),e[v].pb(u);
	}
	res=n-1;
	For(i,1,n) solve(i);
	modint inv2=(mod+1)/2; res*=(inv2^n);
	cout<<res.x;
	return 0;
}