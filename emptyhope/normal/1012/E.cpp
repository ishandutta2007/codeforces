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

#define mod 19260817
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

#define maxn 1000005
#define inf 0x3f3f3f3f

int n,a[maxn],b[maxn],s,k,cnt;
map<int,int>mp; int m;
inline int id(int x){
	if(!mp.count(x))return mp[x]=++m;
	return mp[x];
}
int fa[maxn];
inline int getf(int x){
	while(x^fa[x])x=fa[x]=fa[fa[x]];
	return x;
}

struct edge{
	int to,nxt,w;
}e[maxn];
int tot,head[maxn];
inline void adde(int u,int v,int w){
//	cout<<"adde "<<u<<' '<<v<<' '<<w<<endl;
	e[++tot]=(edge){v,head[u],w};
	head[u]=tot;
	fa[getf(u)]=getf(v);
}

int uu[maxn];

bool vis[maxn];
vi out;
void euler(int u){
	for(int&i=head[u];i;){
		int v=e[i].to;
		int now=e[i].w;
		i=e[i].nxt;
		euler(v);
		out.pb(now);
	}
}

vector< vi >qwq;
void workout(vi o){
	int sz=o.size();
	int tmp=a[o.back()];
	Rep(i,sz-1,1)a[o[i]]=a[o[i-1]];
	a[o[0]]=tmp;
	qwq.pb(o);
}
int qaq[maxn];

signed main()
{
//	freopen("data.out","r",stdin);
//	freopen("my.out","w",stdout);
	n=read(),s=read();
	For(i,1,n)a[i]=read(),b[i]=a[i],fa[i]=i;
//	cout<<n<<endl;
//	For(i,1,n)cout<<a[i]<<' ';puts("");
	sort(b+1,b+n+1);
	For(i,1,n)
		if(a[i]!=b[i]){
			if(!mp.count(a[i])) qaq[id(a[i])]=i;
			if(!mp.count(b[i])) qaq[id(b[i])]=i;
			++cnt,fa[getf(id(a[i]))]=getf(id(b[i]));
		}
	if(cnt>s){
		puts("-1");
		return 0;
	}
	For(i,1,m)
		if(getf(i)==i) ++k,uu[k]=qaq[i];
	s-=cnt;
	int res=k;
	if(s>=2 && k>=2){
		s=min(s,k);
		res+=1;
		res-=(s-1);
		
		vector<int>vec;
		Rep(i,s,1) vec.pb(uu[i]);
		workout(vec);
	}
	
	memset(head,0,sizeof head);tot=0;
	For(i,1,n)fa[i]=i;
	For(i,1,n)
		if(a[i]!=b[i]) adde(id(a[i]),id(b[i]),i);
	
	For(i,1,m)
		if(getf(i)==i){
			out.clear();
			euler(i);
		//	reverse(out.begin(),out.end());
			workout(out);
		}
	For(i,1,n)
		if(a[i]!=b[i])exit(1);
	For(i,2,n)
		if(a[i]<a[i-1])exit(2);
	
	cout<<qwq.size()<<endl;
	for(auto t:qwq){
		cout<<t.size()<<endl;
		for(auto s:t)cout<<s<<' ';puts("");
	}
	return 0;
}
/*
12 15
2 3 1 5 6 4 8 9 7 11 12 10
*/