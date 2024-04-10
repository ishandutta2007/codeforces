// Author -- xyr2005

#include<bits/stdc++.h>

#define lowbit(x) ((x)&(-(x)))
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
#define SZ(x) ((int)x.size())
#define mkpr std::make_pair
#define pb push_back

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef std::pair<int,int> pi;
typedef std::pair<ll,ll> pl;
using std::min;
using std::max;

const int inf=0x3f3f3f3f,Inf=0x7fffffff;
const ll INF=0x3f3f3f3f3f3f3f3f;

std::mt19937 rnd(std::chrono::steady_clock::now().time_since_epoch().count());
template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return (!b)?a:gcd(b,a%b);}
template <typename _Tp>inline _Tp abs(const _Tp &a){return a>=0?a:-a;}
template <typename _Tp>inline void chmax(_Tp &a,const _Tp &b){(a<b)&&(a=b);}
template <typename _Tp>inline void chmin(_Tp &a,const _Tp &b){(b<a)&&(a=b);}
template <typename _Tp>inline void read(_Tp &x)
{
	char ch(getchar());bool f(false);while(!isdigit(ch)) f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch)) x=(((x<<2)+x)<<1)+(ch&15),ch=getchar();
	f&&(x=-x);
}
template <typename _Tp,typename... Args>inline void read(_Tp &t,Args &...args){read(t);read(args...);}
inline int read_str(char *s)
{
	char ch(getchar());while(ch==' '||ch=='\r'||ch=='\n') ch=getchar();
	char *tar=s;*tar=ch,ch=getchar();while(ch!=' '&&ch!='\r'&&ch!='\n'&&ch!=EOF) *(++tar)=ch,ch=getchar();
	return tar-s+1;
}

const int N=500005;
char s[N];
inline ll f(ll x){return 1ll*x*(x+1)>>1;}
struct seg_tr{
	struct Node{
		int ls,rs;
		int tag;
		ll sum;
	}f[N<<1];
	int node_cnt;
	int build(int l,int r)
	{
		int cur=++node_cnt;
		f[cur].tag=-1;
		if(l==r) return cur;
		int mid=(l+r)>>1;
		f[cur].ls=build(l,mid);
		f[cur].rs=build(mid+1,r);
		return cur;
	}
	inline void upd(int cur,int C,int l,int r)
	{
		f[cur].sum=1ll*C*(r-l+1);
		f[cur].tag=C;
	}
	inline void pushdown(int cur,int l,int r)
	{
		if(~f[cur].tag)
		{
			int mid=(l+r)>>1;
			upd(f[cur].ls,f[cur].tag,l,mid);
			upd(f[cur].rs,f[cur].tag,mid+1,r);
			f[cur].tag=-1;
		}
	}
	void Update(int L,int R,int C,int l,int r,int cur)
	{
		if(L<=l&&r<=R)
		{
			upd(cur,C,l,r);
			return;
		}
		pushdown(cur,l,r);
		int mid=(l+r)>>1;
		if(L<=mid) Update(L,R,C,l,mid,f[cur].ls);
		if(R>mid) Update(L,R,C,mid+1,r,f[cur].rs);
		f[cur].sum=f[f[cur].ls].sum+f[f[cur].rs].sum;
	}
	ll Query(int L,int R,int l,int r,int cur)
	{
		if(L<=l&&r<=R) return f[cur].sum;
		pushdown(cur,l,r);
		int mid=(l+r)>>1;
		return (L<=mid?Query(L,R,l,mid,f[cur].ls):0)+(R>mid?Query(L,R,mid+1,r,f[cur].rs):0);
	}
}tr;
int st[N],top;
int val[N];
int main()
{
	int n;read(n);
	read_str(s+1);
	int len=0;
	ll ans=0;
	tr.build(1,n);
	for(int i=1;i<=n;++i)
	{
		if(s[i]=='1')
		{
			++len;
			ans+=f(len);
			val[i]=len;
			while(top&&val[i]>val[st[top]]) --top;
			st[++top]=i,tr.Update(st[top-1]+1,st[top],val[i],1,n,1);
			if(len!=i) ans+=tr.Query(1,i-len,1,n,1);
		}
		else
		{
			if(s[i-1]=='1')
			{
				int j=i;
				while(j>1&&s[j-1]=='1') --j;
				std::reverse(val+j,val+i);
				--top;
				for(int k=j;k<i;++k)
				{
					while(top&&val[k]>val[st[top]]) --top;
					st[++top]=k,tr.Update(st[top-1]+1,st[top],val[k],1,n,1);
				}
			}
			len=0;
			ans+=tr.Query(1,n,1,n,1);
		}
	}
	printf("%lld\n",ans);
	return 0;
}