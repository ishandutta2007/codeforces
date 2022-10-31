// Author -- Frame

#include<bits/stdc++.h>

#define lowbit(x) ((x)&(-x))
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

const int N=(1<<16)+5;
int a[N],b[N],res[N];
int n,q;
std::vector<pi> ans;
std::vector<int> v[N];
std::map<pi,int> mp[N];
int node_cnt,ls[N],rs[N];
int build(int l,int r)
{
	int cur=++node_cnt;
	for(int i=l;i<=r;++i) v[cur].pb(b[i]);
	std::sort(v[cur].begin(),v[cur].end());
	if(l==r) return cur;
	int mid=(l+r)>>1;
	ls[cur]=build(l,mid);rs[cur]=build(mid+1,r);
	return cur;
}
int solve(int L,int R,int cur)
{
	if(!cur) return -1;
	int l=std::lower_bound(v[cur].begin(),v[cur].end(),L)-v[cur].begin();
	int r=std::upper_bound(v[cur].begin(),v[cur].end(),R)-v[cur].begin();
	if(r-l==1) return v[cur][l];
	if(l>=r) return -1;
	if(mp[cur].find(mkpr(l,r))!=mp[cur].end()) return mp[cur][mkpr(l,r)];
	else
	{
		int a=solve(L,R,ls[cur]);
		int b=solve(L,R,rs[cur]);
		if(~a&&~b)
		{
			ans.pb(mkpr(a,b));
			return mp[cur][mkpr(l,r)]=SZ(ans)+n;
		}
		else
		{
			return mp[cur][mkpr(l,r)]=max(a,b);
		}
	}
}
int main()
{
	read(n,q);
	for(int i=1;i<=n;++i) read(a[i]),b[a[i]]=i;
	build(1,n);
	int l,r;
	for(int i=1;i<=q;++i)
	{
		read(l,r);
		res[i]=solve(l,r,1);
	}
	printf("%d\n",SZ(ans)+n);
	for(auto it:ans) printf("%d %d\n",it.first,it.second);
	for(int i=1;i<=q;++i) printf("%d ",res[i]);
	printf("\n");
	return 0;
}