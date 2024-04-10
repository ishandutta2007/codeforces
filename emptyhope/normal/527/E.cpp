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

#define fi first
#define se second
#define pb push_back
#define mkp make_pair
typedef pair<int,int>pii;
typedef vector<int>vi;

#define maxn 1000005
int n,m;
struct edge{
	int to,nxt;
}e[maxn<<1];
int tot=1,head[maxn];
inline void adde(int u,int v){
	e[++tot]=(edge){v,head[u]};
	head[u]=tot;
}

int d[maxn];
inline void add(int u,int v){
	d[u]++,d[v]++;
	adde(u,v),adde(v,u);
}
int len;
bool vis[maxn];
void dfs(int u)
{
	for(int&i=head[u];i;i=e[i].nxt){
		if(vis[i>>1])continue;
		int v=e[i].to;
		vis[i>>1]=1;
		dfs(v);
		if((++len)&1)cout<<u<<' '<<v<<endl;
		else cout<<v<<' '<<u<<endl;
	}
}

signed main()
{
	n=read(),m=read();
	For(i,1,m){
		int u=read(),v=read();
		add(u,v); 
	}
	vector<int>o;
	For(i,1,n)if(d[i]&1)o.pb(i);
	for(int i=0;i<o.size();i+=2) add(o[i],o[i+1]),++m;
	if(m&1) ++m,add(1,1);
	cout<<m<<endl;
	dfs(1);
	return 0;
}