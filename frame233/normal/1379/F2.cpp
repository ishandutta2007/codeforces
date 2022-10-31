// Author -- Frame

#include<bits/stdc++.h>

#define lowbit(x) ((x)&(-(x)))
#define Finline __inline__ __attribute__ ((always_inline))
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
#define SZ(x) ((int)x.size())
#define mkpr std::make_pair
#define pb push_back

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef std::pair<int,int> pi;
typedef std::pair<ll,ll> pl;

const int inf=0x3f3f3f3f,Inf=0x7fffffff;
const ll INF=0x3f3f3f3f3f3f3f3f;

Finline uint rnd()
{
	static uint seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return (!b)?a:gcd(b,a%b);}
template <typename _Tp>Finline _Tp abs(const _Tp &a){return a>=0?a:-a;}
template <typename _Tp>Finline _Tp max(const _Tp &a,const _Tp &b){return a<b?b:a;}
template <typename _Tp>Finline _Tp min(const _Tp &a,const _Tp &b){return a<b?a:b;}
template <typename _Tp>Finline void chmax(_Tp &a,const _Tp &b){(a<b)&&(a=b);}
template <typename _Tp>Finline void chmin(_Tp &a,const _Tp &b){(b<a)&&(a=b);}
template <typename _Tp>Finline void read(_Tp &x)
{
	char ch(getchar());
	bool f(false);
	while(ch<48||ch>57) f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();
	while(ch>=48&&ch<=57) x=(((x<<2)+x)<<1)+(ch&15),ch=getchar();
	if(f) x=-x;
}
template <typename _Tp,typename... Args>Finline void read(_Tp &t,Args &...args){read(t);read(args...);}
Finline int read_str(char *s)
{
	char ch(getchar());
	while(ch==' '||ch=='\r'||ch=='\n') ch=getchar();
	char *tar=s;
	*tar=ch,ch=getchar();
	while(ch!=' '&&ch!='\r'&&ch!='\n'&&ch!=EOF) *(++tar)=ch,ch=getchar();
	return tar-s+1;
}

const int N=200005;
std::set<int> S1[N],S2[N];
int ls[N<<1],rs[N<<1],minn[N<<1],maxx[N<<1],node_cnt;
bool val[N<<1];
Finline void PushUp(int x)
{
	minn[x]=min(minn[ls[x]],minn[rs[x]]);
	maxx[x]=max(maxx[ls[x]],maxx[rs[x]]);
	val[x]=val[ls[x]]||val[rs[x]]||(minn[ls[x]]<=maxx[rs[x]]);
}
int build(int l,int r)
{
	int cur=++node_cnt;
	if(l==r)
	{
		val[cur]=*S1[l].begin()<=*--S2[l].end();
		minn[cur]=*S1[l].begin(),maxx[cur]=*--S2[l].end();
		return cur;
	}
	int mid=(l+r)>>1;
	ls[cur]=build(l,mid);
	rs[cur]=build(mid+1,r);
	return PushUp(cur),cur;
}
void Update(int pos,int l,int r,int cur)
{
	if(l==r)
	{
		val[cur]=*S1[l].begin()<=*--S2[l].end();
		minn[cur]=*S1[l].begin(),maxx[cur]=*--S2[l].end();
		return;
	}
	int mid=(l+r)>>1;
	if(pos<=mid) Update(pos,l,mid,ls[cur]);
	else Update(pos,mid+1,r,rs[cur]);
	PushUp(cur);
}
std::set<pi> S;
int main()
{
	int n,m,q;
	read(n,m,q);
	for(int i=1;i<=n;++i) S1[i].insert(inf),S2[i].insert(0);
	build(1,n);
	int x,y;
	while(q--)
	{
		read(x,y);
		if(S.find(mkpr(x,y))==S.end())
		{
			if(y&1) S1[(x+1)>>1].insert((y+1)>>1);
			else S2[(x+1)>>1].insert((y+1)>>1);
			S.insert(mkpr(x,y));
		}
		else
		{
			if(y&1) S1[(x+1)>>1].erase((y+1)>>1);
			else S2[(x+1)>>1].erase((y+1)>>1);
			S.erase(mkpr(x,y));
		}
		Update((x+1)>>1,1,n,1);
		puts(val[1]?"NO":"YES");
	}
	return 0;
}