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
Finline int get()
{
	char ch=getchar();
	while(ch!='F'&&ch!='S'&&ch!='E') ch=getchar();
	char qwq=getchar();
	while(qwq!='\n') qwq=getchar();
	if(ch=='F') return 0;
	if(ch=='S') return 1;
	if(ch=='E') return 2;
	return -1;
}
Finline int print(int l1,int r1,int l2,int r2)
{
	printf("? %d %d\n",r1-l1+1,r2-l2+1);
	for(int i=l1;i<=r1;++i) printf("%d ",i);
	printf("\n");
	for(int i=l2;i<=r2;++i) printf("%d ",i);
	printf("\n");
	fflush(stdout);
	return get();
}
void MAIN()
{
	int n,k;
	read(n,k);
	std::vector<int> v(n-1);
	for(int i=0;i+1<n;++i) v[i]=i+2;
	std::mt19937 rnd(std::chrono::steady_clock::now().time_since_epoch().count());
	std::shuffle(v.begin(),v.end(),rnd);
	for(int i=0;i<30&&i<SZ(v);++i)
	{
		printf("? 1 1\n%d\n%d\n",1,v[i]);
		fflush(stdout);
		if(get()==1)
		{
			printf("! 1\n");
			fflush(stdout);
			return;
		}
	}
	int cur=1;
	while(cur<n)
	{
		int t=min(n,cur<<1);
		if(print(1,t-cur,cur+1,t)==2)
		{
			cur=t;
		}
		else
		{
			int l=cur+1,r=t;
			while(l<r)
			{
				int mid=(l+r)>>1;
				if(print(1,mid-cur,cur+1,mid)==0) r=mid;
				else l=mid+1;
			}
			printf("! %d\n",l);
			fflush(stdout);
			return;
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