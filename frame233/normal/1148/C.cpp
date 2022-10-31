// Author -- Frame

#include<cstdio>
#include<cstring>
#include<algorithm>

#define Finline __inline__ __attribute__ ((always_inline))

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;

const int inf=0x3f3f3f3f,Inf=0x7fffffff;
const ll INF=0x7ffffffffffffff;

template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return (!b)?a:gcd(b,a%b);}
template <typename _Tp>Finline _Tp abs(const _Tp &a){return a>0?a:-a;}
template <typename _Tp>Finline _Tp max(const _Tp &a,const _Tp &b){return a<b?b:a;}
template <typename _Tp>Finline _Tp min(const _Tp &a,const _Tp &b){return a<b?a:b;}
template <typename _Tp>Finline void chmax(_Tp &a,const _Tp &b){(a<b)&&(a=b);}
template <typename _Tp>Finline void chmin(_Tp &a,const _Tp &b){(a>b)&&(a=b);}
template <typename _Tp>Finline void read(_Tp& x)
{
    register char ch(getchar());
    bool f(false);
    while(ch<48||ch>57) f|=ch==45,ch=getchar();
    x=ch&15,ch=getchar();
    while(ch>=48&&ch<=57) x=(((x<<2)+x)<<1)+(ch&15),ch=getchar();
    if(f) x=-x;
}
template <typename _Tp,typename... Args>Finline void read(_Tp& t, Args&... args)
{
    read(t);read(args...);
}
Finline int read_str(char *s)
{
	register char ch(getchar());
	while(ch<65||ch>122||(ch>90&&ch<97)) ch=getchar();
	register char *tar=s;
	*tar=ch,ch=getchar();
	while((ch>=65&&ch<=90)||(ch>=97&&ch<=122)) *(++tar)=ch,ch=getchar();
	return tar-s+1;
}

const int N=300005;
int a[N],p[N];
int id[N];
int ans[N<<3][2],pos;
Finline bool cmp(int A,int B){return a[A]<a[B];}
int main()
{
	int n;
	read(n);
	for(int i=1;i<=n;++i)
	{
		read(a[i]);
		p[a[i]]=i;
		id[i]=i;
	}
	std::sort(id+1,id+n+1);
	for(int _=1;_<=n;++_)
	{
		int i=id[_];
		if(i==p[i]) continue;
		int tmp1=(i>(n>>1))?1:n,tmp2=(p[i]>(n>>1))?1:n;
		if(tmp1==1&&tmp2==1)
		{
			ans[++pos][0]=1;
			ans[pos][1]=i;
			ans[++pos][0]=1;
			ans[pos][1]=p[i];
			ans[++pos][0]=1;
			ans[pos][1]=i;
			//1 i p
			//i 1 p
			//p 1 i
			//1 p i
		}
		else if(tmp1==1&&tmp2==n)
		{
			if(p[i]==1)
			{
				ans[++pos][0]=p[i];
				ans[pos][1]=n;
				ans[++pos][0]=1;
				ans[pos][1]=i;
				ans[++pos][0]=1;
				ans[pos][1]=n;
				ans[++pos][0]=1;
				ans[pos][1]=i;
				ans[++pos][0]=p[i];
				ans[pos][1]=n;
			}
			else
			{
				ans[++pos][0]=1;
				ans[pos][1]=i;
				ans[++pos][0]=p[i];
				ans[pos][1]=n;
				ans[++pos][0]=1;
				ans[pos][1]=n;
				ans[++pos][0]=p[i];
				ans[pos][1]=n;
				ans[++pos][0]=1;
				ans[pos][1]=i;
			}
			//1 p i n
			//i p 1 n
			//i n 1 p
			//p n 1 i
			//1 n p i
			//1 i p n
		}
		else if(tmp1==n&&tmp2==1)
		{
			if(i==1)
			{
				ans[++pos][0]=i;
				ans[pos][1]=n;
				ans[++pos][0]=1;
				ans[pos][1]=p[i];
				ans[++pos][0]=1;
				ans[pos][1]=n;
				ans[++pos][0]=1;
				ans[pos][1]=p[i];
				ans[++pos][0]=i;
				ans[pos][1]=n;
			}
			else
			{
				ans[++pos][0]=1;
				ans[pos][1]=p[i];
				ans[++pos][0]=i;
				ans[pos][1]=n;
				ans[++pos][0]=1;
				ans[pos][1]=n;
				ans[++pos][0]=i;
				ans[pos][1]=n;
				ans[++pos][0]=1;
				ans[pos][1]=p[i];
			}
			//1 i p n
			//p i 1 n
			//p n 1 i
			//i n 1 p
			//1 n i p
			//1 p i n
		}
		else
		{
			ans[++pos][0]=n;
			ans[pos][1]=p[i];
			ans[++pos][0]=n;
			ans[pos][1]=i;
			ans[++pos][0]=n;
			ans[pos][1]=p[i];
		}
		p[a[i]]=p[i];
		std::swap(a[i],a[p[i]]);
	}
	printf("%d\n",pos);
	for(int i=1;i<=pos;++i) printf("%d %d\n",ans[i][0],ans[i][1]);
	return 0;
}