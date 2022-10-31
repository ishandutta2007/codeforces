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

const int N=100005;
int a[N];
struct node{
	int val,cnt;
	Finline bool operator < (const node &o)const
	{
		return cnt<o.cnt;
	}
};
struct Node{
	int val,id;
	Finline bool operator < (const Node &o)const
	{
		return val<o.val;
	}
};
std::priority_queue<node> q;
int cnt[N],n,x,y;
int b[N],c[N],d[N];
int qwq;
std::vector<Node> solve(std::vector<Node> v)
{
	while(!q.empty()) q.pop();
	memset(cnt,0,sizeof(cnt));
	for(auto it:v) ++cnt[it.val];
	for(int i=1;i<=n+1;++i) if(cnt[i]) q.push((node){i,cnt[i]});
	int lim=n-y;std::vector<Node> ans;
	while(lim--)
	{
		node tmp=q.top();q.pop();--cnt[tmp.val];
		if(--tmp.cnt) q.push(tmp);
	}
	for(auto it:v)
	{
		if(cnt[it.val]) ans.pb(it),--cnt[it.val];
		else ans.pb((Node){qwq,it.id});
	}
	return ans;
}
int __[N];
void MAIN()
{
	memset(cnt,0,sizeof(cnt));memset(b,0,sizeof(b));memset(__,0,sizeof(__));
	while(!q.empty()) q.pop();
	read(n,x,y);
	for(int i=1;i<=n;++i) read(a[i]),++cnt[a[i]];
	for(int i=1;i<=n+1;++i) if(cnt[i]) q.push((node){i,cnt[i]});else qwq=i;
	int lim=x;
	std::vector<int> v;
	std::vector<Node> _;
	while(lim--)
	{
		node tmp=q.top();q.pop();v.pb(tmp.val);--cnt[tmp.val];
		if(--tmp.cnt) q.push(tmp);
	}
	std::multiset<int> S;
	for(auto it:v) S.insert(it);
	for(int i=1;i<=n;++i)
	{
		auto it=S.find(a[i]);
		if(it!=S.end())
		{
			b[i]=a[i];
			S.erase(it);
		}
		else _.pb((Node){a[i],i});
	}
	std::sort(_.begin(),_.end());
	_=solve(_);
	for(int i=0;i<SZ(_);++i) c[i]=_[i].id;
	int maxx=0;
	for(int i=0;i<SZ(_);++i)
	{
		if(_[i].val==qwq) continue;
		int j=i;
		while(j+1<SZ(_)&&_[j+1].val==_[i].val) ++j;
		chmax(maxx,j-i+1);
		i=j;
	}
	std::vector<int> ___;
	for(int i=maxx;i<SZ(_);++i) ___.pb(_[i].val);
	for(int i=0;i<maxx;++i) ___.pb(_[i].val);
	for(int i=0;i<SZ(___);++i) b[c[i]]=___[i];
	
	int ans1=0,ans2=0;
	for(int i=1;i<=n;++i) ans1+=a[i]==b[i],++__[a[i]];
	for(int i=1;i<=n;++i) if(__[b[i]]) ++ans2,--__[b[i]];
	if(ans1==x&&ans2==y)
	{
		printf("YES\n");
		for(int i=1;i<=n;++i) printf("%d ",b[i]);
		printf("\n");
	}
	else printf("NO\n");
}
int main()
{
	int _;
	read(_);
	while(_--) MAIN();
	return 0;
}