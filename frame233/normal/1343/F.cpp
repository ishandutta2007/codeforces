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

const int N=205;
int siz[N];
std::bitset<N> B[N+1],last[N];
std::vector<int> v[N];
int a[N];
bool used[N];
bool vis[N];
void MAIN()
{
	int n;
	read(n);
	int x,y;
	for(int i=1;i<n;++i)
	{
		read(x);
		siz[i]=x;
		v[i].resize(x);
		B[i].reset();
		for(int j=0;j<x;++j)
		{
			read(y);
			v[i][j]=y;
			B[i].set(y);
		}
	}
	auto solve=[&](int id,int opt)->bool
	{
		memset(used,0,(n+3));
		memset(vis,0,(n+3));
		for(int i=0;i<=n;++i) last[i].reset();
		used[id]=true;
		a[1]=v[id][opt];
		a[2]=v[id][!opt];
		last[1].set(a[1]);
		last[1].set(a[2]);
		last[2].set(a[2]);
		vis[a[1]]=vis[a[2]]=true;
		std::bitset<N> tmp;
		for(int j=3;j<=n;++j)
		{
			bool flag=false;
			for(int k=1;k<n;++k)
			{
				if(!used[k])
				{
					int qwq=j-siz[k]+1;
					if(qwq<=0) continue;
					if((B[k]&last[qwq])==last[qwq])
					{
						tmp=B[k]^last[qwq];
						if(tmp.count()==1)
						{
							a[j]=tmp._Find_first();
							if(vis[a[j]]) continue;
							used[k]=true;
							flag=true;
							vis[a[j]]=true;
							break;
						}
					}
				}
			}
			if(!flag) return false;
			for(int i=1;i<=j;++i) last[i].set(a[j]);
		}
		for(int i=1;i<=n;++i) printf("%d ",a[i]);
		printf("\n");
		return true;
	};
	for(int i=1;i<n;++i)
	{
		if(siz[i]==2)
		{
			if(solve(i,0)) return;
			if(solve(i,1)) return;
		}
	}
}
int main()
{
	int _;
	read(_);
	while(_--) MAIN();
	return 0;
}