// Author -- Frame

#pragma GCC optimize(3)
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

const int N=100005;

int main()
{
	int n,last,x,last_last=-1;
	read(n);
	read(last);
	ll ans=0;
	for(int i=2;i<=n;++i)
	{
		read(x);
		if(last==2&&x==3)
		{
			printf("Infinite\n");
			return 0;
		}
		if(last==3&&x==2)
		{
			printf("Infinite\n");
			return 0;
		}
		ans+=x+last;
		if(last_last==3&&last==1&&x==2) --ans;
		last_last=last;
		last=x;
	}
	printf("Finite\n%lld\n",ans);
	return 0;
}
//Frame