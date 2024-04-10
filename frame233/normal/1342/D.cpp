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
typedef std::pair<int,int> pl;

const int inf=0x3f3f3f3f,Inf=0x7fffffff;
const ll INF=0x7fffffffffffffff;

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
template <typename _Tp,typename... Args>Finline void read(_Tp &t,Args &...args)
{
	read(t);read(args...);
}
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
int a[N],c[N];
int siz[N],last[N];
int pre[N];
struct node{
	int val,id;
	Finline bool operator < (const node &o)const
	{
		return val==o.val?id<o.id:val<o.val;
	}
};
std::set<node> S;
std::vector<int> v[N];
int main()
{
	int n,k;
	read(n,k);
	for(int i=1;i<=n;++i) read(a[i]);
	for(int i=1;i<=k;++i) read(c[i]);
	for(int i=1;i<=k;++i)
	{
		if(c[i-1]==c[i])
		{
			pre[i]=pre[i-1];
		}
		else
		{
			pre[i]=i-1;
		}
	}
	std::sort(a+1,a+n+1,[](int a,int b)->int{return a>b;});
	int ans=0;
	for(int i=1;i<=n;++i)
	{
		auto it=S.lower_bound((node){a[i],-1});
		if(it==S.end())
		{
			++ans;
			siz[ans]=0;
			last[ans]=k;
			it=S.insert((node){last[ans],ans}).first;
		}
		v[it->id].pb(a[i]);
		node val=*it;
		S.erase(it);
		++siz[val.id];
		if(siz[val.id]==c[last[val.id]]) last[val.id]=pre[last[val.id]];
		S.insert((node){last[val.id],val.id});
	}
	printf("%d\n",ans);
	for(int i=1;i<=ans;++i)
	{
		printf("%d ",SZ(v[i]));
		for(auto it:v[i]) printf("%d ",it);
		printf("\n");
	}
	return 0;
}