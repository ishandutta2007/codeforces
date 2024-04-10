#include<bits/stdc++.h>
#define For(i,a,b) for(register int i=(a);i<=(b);++i)
#define Rep(i,a,b) for(register int i=(a);i>=(b);--i)
#define int long long
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

#define maxn 100005
#define inf 0x3f3f3f3f
int n,k,a[maxn];
vector<int>e[maxn];

namespace qaq{
	
int dep[maxn],d[maxn],now;
int val[45];
void dfs(int u,int pa)
{
	if(pa)dep[u]=dep[pa]+1;
	val[dep[u]%(2*k)]^=a[u];
	d[u]=(dep[u]/k);
	if(d[u]&1)now^=a[u];
	for(auto v:e[u])if(v!=pa)dfs(v,u);
}
int work(int u)
{
//	cout<<"work "<<u<<endl;
	For(i,0,2*k-1)val[i]=0;
	now=0,dep[u]=0,dfs(u,0);
	cout<<u<<" "<<endl;
	For(i,0,2*k-1)cout<<val[i]<<' ';puts("");
	//cout<<now<<" ";
	return now;
}
void QAQ(){
	puts("--------");
	For(i,1,n)work(i);
	puts("---------");
}

}

int now[45],p;
int f[maxn][45],g[maxn][45];
int dep[maxn],res[maxn];
void dfs1(int u,int pa){
	if(pa)dep[u]=dep[pa]+1;
	f[u][0] = a[u];
	for(auto v:e[u])
		if(v!=pa){
			dfs1(v,u);
			For(i,0,p-1) f[u][i]^=f[v][(i-1+p)%p];
		}
}

void dfs2(int u,int pa)
{
	res[u]=0;
	For(i,k,p-1)res[u]^=g[u][i];
//	cout<<u<<endl;
//	For(i,0,p-1)cout<<g[u][i]<<" ";puts("");
	for(auto v:e[u]){
		if(v==pa)continue;
		For(i,0,p-1) now[i]=g[u][i]^f[v][(i-1+p)%p];
	//	int tmp=now[p-1];
	//	For(i,1,p-1) now[i]=now[i-1];
	//	now[0]=tmp;
		For(i,0,p-1) g[v][i]=now[(i-1+p)%p]^f[v][i];
		dfs2(v,u);
	}
}

signed main()
{
	n=read(),k=read();
	For(i,2,n){
		int u=read(),v=read();
		e[u].pb(v),e[v].pb(u);
	}
	For(i,1,n)a[i]=read();
	//For(i,1,n)cout<<work(i)<<endl;
	p=2*k;
	dfs1(1,0);
	For(i,0,p-1) g[1][i]=f[1][i];
	dfs2(1,0);
	
//	qaq::QAQ();
	For(i,1,n){
		if(res[i])cout<<1<<" ";
		else cout<<0<<' ';
	}puts("");
	return 0;
}