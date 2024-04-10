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
struct node1{
	int a,b,id;
	Finline bool operator < (const node1 &o)const&{return b>o.b;}
}a[N];
struct node2{
	int a,b,id;
	Finline bool operator < (const node2 &o)const&{return a<o.a;}
}b[N];
int main()
{
	int n,x,y,pos1=0,pos2=0;
	read(n);
	for(int i=1;i<=n;++i)
	{
		read(x,y);
		if(x<y)
		{
			a[++pos1]=(node1){x,y,i};
		}
		else
		{
			b[++pos2]=(node2){y,x,i};
		}
	}
	if(pos1<pos2)
	{
		std::sort(b+1,b+pos2+1);
		printf("%d\n",pos2);
		for(int i=1;i<=pos2;++i)
		{
			printf("%d ",b[i].id);
		}
		printf("\n");
	}
	else
	{
		std::sort(a+1,a+pos1+1);
		printf("%d\n",pos1);
		for(int i=1;i<=pos1;++i)
		{
			printf("%d ",a[i].id);
		}
		printf("\n");
	}
    return 0;
}