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
	register char *tar=s;
	*tar=ch,ch=getchar();
	while((ch>=65&&ch<=90)||(ch>=97&&ch<=122)) *(++tar)=ch,ch=getchar();
	return tar-s+1;
}

const int N=100005;
ll a[N],b[N];
int main()
{
	int _;
	read(_);
	while(_--)
	{
		int n,pos=0;
		read(n);
		for(int i=1;i<=n;++i) read(a[i]);
		std::sort(a+1,a+n+1);
		int l=1,r=n;
		ll ans=a[1]*a[n];
		while(l<=r)
		{
			if(ans!=a[l]*a[r])
			{
				ans=-1;
				break;
			}
			++l,--r;
		}
		if(~ans)
		{
			for(ll i=2;i*i<=ans;++i)
			{
				if(!(ans%i))
				{
					b[++pos]=i;
					if(i*i!=ans) b[++pos]=ans/i;
				}
			}
			if(pos!=n) ans=-1;
			else
			{
				std::sort(b+1,b+pos+1);
				for(int i=1;i<=pos;++i)
				{
					if(a[i]!=b[i])
					{
						ans=-1;
						break;
					}
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
//