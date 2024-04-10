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
const ll INF=0x7fffffffffffffff;

Finline uint rnd()
{
	static uint seed=0x05ad13b4;
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
int A[55][55],cnt[55];
int t[55];
void MAIN()
{
	int n,m,a,b;
	read(n,m,a,b);
	if(n*a!=b*m)
	{
		printf("NO\n");
		return;
	}
	memset(A,0,sizeof(A));
	memset(cnt,0,sizeof(cnt));
	for(int i=0;i<m;++i) t[i]=i;
	for(int i=0;i<n;++i)
	{
		std::sort(t,t+m,[&](int a,int b)->bool{return cnt[a]<cnt[b];});
		for(int j=0;j<a;++j) ++cnt[t[j]],A[i][t[j]]=1;
	}
	bool flag=true;
	for(int i=0;i<m;++i) flag&=cnt[i]==b;
	if(!flag)
	{
		printf("NO\n");
		return;
	}
	printf("YES\n");
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<m;++j)
		{
			printf("%d",A[i][j]);
		}
		printf("\n");
	}
}
int main()
{
	int _;
	read(_);
	while(_--) MAIN();
	return 0;
}