// Author -- Frame

#include<cstdio>
#include<cstring>
#include<algorithm>

#define Finline __inline__ __attribute__ ((always_inline))

typedef long long ll;

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
	register int pos(0);
	s[pos]=ch,ch=getchar();
	while((ch>=65&&ch<=90)||(ch>=97&&ch<=122)) s[++pos]=ch,ch=getchar();
	return pos+1;
}

const int N=300005;
struct node{
	int a,pos;
	Finline bool operator < (const node &b)const{return a<b.a;}
}a[N];
int main()
{
	int n,maxx=0,minn=0x7fffffff;
	read(n);
	for(int i=1;i<=n;++i)
	{
		read(a[i].a);
		a[i].pos=i;
	}
	std::sort(a+1,a+n+1);
	int ans=0x7fffffff;
	for(int i=n;i>=1;--i)
	{
		chmax(maxx,a[i].pos);
		chmin(minn,a[i].pos);
		if(maxx!=a[i].pos) chmin(ans,a[i].a/(maxx-a[i].pos));
		if(minn!=a[i].pos) chmin(ans,a[i].a/(a[i].pos-minn));
	}
	printf("%d\n",ans);
	return 0;
}