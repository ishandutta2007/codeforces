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

const int N=100005;
struct edge{
	int v,nxt;
}c[N<<1];
int front[N],edge_cnt;
Finline void add(int u,int v)
{
	c[++edge_cnt]=(edge){v,front[u]};
	front[u]=edge_cnt;
}
int L[N],R[N];
bool valid[N][2];
int C[N];
std::vector<int> v;
bool check(int x,int col)
{
	if(~C[x])
	{
		if(C[x]==col) return true;
		return false;
	}
	if(!valid[x][col]) return false;
	v.pb(x);
	C[x]=col;
	for(int i=front[x];i;i=c[i].nxt)
	{
		if(!check(c[i].v,col^1))
		{
			return false;
		}
	}
	return true;
}
int main()
{
	memset(C,255,sizeof(C));
	int t,T;
	read(t,T);
	int n,m;
	read(n,m);
	int n1=inf,n2=0;
	for(int i=1;i<=n;++i)
	{
		read(L[i],R[i]);
		chmin(n1,R[i]);
		chmax(n2,L[i]);
	}
	if(n1+n2<t)
	{
		n2=t-n1;
	}
	else if(n1+n2>T)
	{
		n1=T-n2;
	}
	if(n1<0||n2<0)
	{
		printf("IMPOSSIBLE\n");
		return 0;
	}
	for(int i=1;i<=n;++i)
	{
		valid[i][0]=L[i]<=n1&&n1<=R[i];
		valid[i][1]=L[i]<=n2&&n2<=R[i];
	}
	int x,y;
	for(int i=1;i<=m;++i)
	{
		read(x,y);
		add(x,y),add(y,x);
	}
	for(int i=1;i<=n;++i)
	{
		if(C[i]==-1)
		{
			v.clear();
			if(check(i,0)) continue;
			for(auto it:v) C[it]=-1;
			v.clear();
			if(check(i,1)) continue;
			printf("IMPOSSIBLE\n");
			return 0;
		}
	}
	printf("POSSIBLE\n%d %d\n",n1,n2);
	for(int i=1;i<=n;++i) printf("%d",C[i]+1);
	printf("\n");
	return 0;
}