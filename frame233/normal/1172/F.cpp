// Author -- Frame

#include<bits/stdc++.h>

#define lowbit(x) ((x)&(-x))
#define Finline __inline__ __attribute__ ((always_inline))
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
#define SZ(x) ((int)x.size())

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;

const int inf=0x3f3f3f3f,Inf=0x7fffffff;
const ll INF=0x7fffffffffffffff;
const double eps=1e-10;

template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return (!b)?a:gcd(b,a%b);}
template <typename _Tp>Finline _Tp abs(const _Tp &a){return a>=0?a:-a;}
template <typename _Tp>Finline _Tp max(const _Tp &a,const _Tp &b){return a<b?b:a;}
template <typename _Tp>Finline _Tp min(const _Tp &a,const _Tp &b){return a<b?a:b;}
template <typename _Tp>Finline void chmax(_Tp &a,const _Tp &b){(a<b)&&(a=b);}
template <typename _Tp>Finline void chmin(_Tp &a,const _Tp &b){(b<a)&&(a=b);}
template <typename _Tp>Finline bool _cmp(const _Tp &a,const _Tp &b){return abs(a-b)<=eps;}
template <typename _Tp>Finline void read(_Tp &x)
{
	register char ch(getchar());
	bool f(false);
	while(ch<48||ch>57) f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();
	while(ch>=48&&ch<=57) x=(((x<<2)+x)<<1)+(ch&15),ch=getchar();
	if(f) x=-x;
}
template <typename _Tp,typename... Args>Finline void read(_Tp &t,Args &...args)
{
	read(t);read(args...);
}
Finline int read_str(char *s)
{
	register char ch(getchar());
	while(ch==' '||ch=='\r'||ch=='\n') ch=getchar();
	register char *tar=s;
	*tar=ch,ch=getchar();
	while(ch!=' '&&ch!='\r'&&ch!='\n'&&ch!=EOF) *(++tar)=ch,ch=getchar();
	return tar-s+1;
}

const int N=1000005;
int p;
int a[N];
ll ans;
struct seg_tr{
	struct Node{
		int ls,rs;
		ll sum;
		std::vector<ll> c;
	}f[N<<1];
	int node_cnt;
	Finline void PushUp(int x)
	{
		f[x].sum=f[f[x].ls].sum+f[f[x].rs].sum;
		std::vector<ll> c1=f[f[x].ls].c,c2=f[f[x].rs].c;
		ll s1=f[f[x].ls].sum;
		int pos=0;
		for(int i=0;i+1<SZ(c1);++i)
		{
			if(pos) --pos;
			ll l=c1[i]-1ll*i*p+s1;
			ll r=c1[i+1]-1-1ll*i*p+s1;
			while(pos+1<SZ(c2))
			{
				if(c2[pos]>r)
				{
					if(pos) --pos;
					break;
				}
				if(l<=c2[pos]) chmin(f[x].c[i+pos],c2[pos]+1ll*i*p-s1);
				else if(c2[pos+1]>l) chmin(f[x].c[i+pos],c1[i]);
				++pos;
			}
		}
	}
	int build(int l,int r)
	{
		int cur=++node_cnt;
		if(l==r)
		{
			f[cur].c.resize(3);
			f[cur].sum=a[l];
			f[cur].c[0]=-1e18;
			f[cur].c[1]=p-a[l];
			f[cur].c[2]=1e18;
			return cur;
		}
		int mid=(l+r)>>1;
		f[cur].ls=build(l,mid);
		f[cur].rs=build(mid+1,r);
		f[cur].c.resize(r-l+3);
		for(auto &&it:f[cur].c) it=1e18;
		PushUp(cur);
		return cur;
	}
	void Query(int L,int R,int l,int r,int cur)
	{
		if(L<=l&&r<=R)
		{
			int l=0,r=SZ(f[cur].c)-1;
			while(l<r)
			{
				int mid=(l+r+1)>>1;
				if(ans>=f[cur].c[mid]) l=mid;
				else r=mid-1;
			}
			ans-=1ll*l*p;
			ans+=f[cur].sum;
			return;
		}
		int mid=(l+r)>>1;
		if(L<=mid) Query(L,R,l,mid,f[cur].ls);
		if(R>mid) Query(L,R,mid+1,r,f[cur].rs);
	}
}tr;
int main()
{
	int n,m;
	read(n,m,p);
	for(int i=1;i<=n;++i) read(a[i]);
	tr.build(1,n);
	int x,y;
	while(m--)
	{
		read(x,y);
		ans=0;
		tr.Query(x,y,1,n,1);
		printf("%lld\n",ans);
	}
	return 0;
}