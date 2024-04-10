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

const int N=800005;
int n,k,m;
struct node{
	int a,b,ans;
	Finline node operator + (const node &o)const
	{
		int tmp=min(a,o.b);
		return (node){a+o.a-tmp,b+o.b-tmp,ans+o.ans+tmp};
	}
};
struct Node{
	int ls,rs;
	node val;
}f[N<<1];
int node_cnt;
Finline void PushUp(int x)
{
	f[x].val=f[f[x].ls].val+f[f[x].rs].val;
}
int build(int l=1,int r=n<<2)
{
	int cur=++node_cnt;
	if(l==r)
	{
		if(l&1) f[cur].val=(node){0,0,0};
		else f[cur].val=(node){0,1,0};
		return cur;
	}
	int mid=(l+r)>>1;
	f[cur].ls=build(l,mid);f[cur].rs=build(mid+1,r);
	PushUp(cur);
	return cur;
}
void Update(int pos,int C,int l=1,int r=n<<2,int cur=1)
{
	if(l==r)
	{
		f[cur].val.a+=C;
		return;
	}
	int mid=(l+r)>>1;
	if(pos<=mid) Update(pos,C,l,mid,f[cur].ls);
	else Update(pos,C,mid+1,r,f[cur].rs);
	PushUp(cur);
}
node Query(int L,int R,int l=1,int r=n<<2,int cur=1)
{
	if(L<=l&&r<=R) return f[cur].val;
	int mid=(l+r)>>1;
	if(L<=mid&&R>mid) return Query(L,R,l,mid,f[cur].ls)+Query(L,R,mid+1,r,f[cur].rs);
	return L<=mid?Query(L,R,l,mid,f[cur].ls):Query(L,R,mid+1,r,f[cur].rs);
}
std::set<pi> S;
std::multiset<int> s;
int main()
{
	read(n,k,m);
	build();
	int x,y;
	while(m--)
	{
		read(x,y);
		pi tmp=mkpr(x,y);
		int qwq=y+abs(x-k);
		if(S.find(tmp)!=S.end()) Update(qwq*2-1,-1),s.erase(s.find(qwq)),S.erase(tmp);
		else Update(qwq*2-1,1),s.insert(qwq),S.insert(tmp);
		if(s.empty())
		{
			printf("0\n");
		}
		else
		{
			int tmp=max(n,*--s.end());
			printf("%d\n",tmp-n+SZ(s)-Query(1,tmp*2).ans);
		}
	}
	return 0;
}