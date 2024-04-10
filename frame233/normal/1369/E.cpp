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

const int N=200005;
int w[N];
struct node{
	int val,id;
	Finline bool operator == (const node &o)const
	{
		return val==o.val&&id==o.id;
	}
	Finline bool operator < (const node &o)const
	{
		return val==o.val?id>o.id:val>o.val;
	}
};
struct heap{
	std::priority_queue<node> q1,q2;
	int siz;
	Finline bool empty(){return !siz;}
	Finline int size(){return siz;}
	Finline void push(const node &o){q1.push(o);++siz;}
	Finline void pop(const node &o){q2.push(o);--siz;}
	Finline node top()
	{
		while(!q2.empty()&&q1.top()==q2.top()) q1.pop(),q2.pop();
		return q1.top();
	}
}q;
std::vector<int> v[N],e[N];
int s[N];
bool used[N];
bool vis[N];
std::vector<int> valid;
int main()
{
	int n,m;
	read(n,m);
	for(int i=1;i<=n;++i) read(w[i]);
	int x,y;
	for(int i=1;i<=m;++i)
	{
		read(x,y);
		e[i].pb(x),e[i].pb(y);
		v[x].pb(i),v[y].pb(i);
		++s[x],++s[y];
	}
	for(int i=1;i<=n;++i)
	{
		s[i]-=w[i];
		if(s[i]<=0) valid.pb(i);
	}
	std::vector<int> ans;
	for(int i=1;i<=n;++i)
	{
		if(valid.empty()) return puts("DEAD"),0;
		int x=valid.back();valid.pop_back();
		vis[x]=true;
		for(auto it:v[x])
		{
			if(used[it]) continue;
			ans.pb(it);
			used[it]=true;
			for(auto itt:e[it]) if(!vis[itt]) if(!--s[itt]) valid.pb(itt);
		}
	}
	std::reverse(ans.begin(),ans.end());
	puts("ALIVE");
	for(auto it:ans) printf("%d ",it);
	printf("\n");
	return 0;
}