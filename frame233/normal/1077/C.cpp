// Author -- Frame

#include<cstdio>
#include<cstring>
#include<algorithm>

typedef long long ll;

template <typename T>T gcd(const T &a,const T &b){return (!b)?a:gcd(b,a%b);}
template <typename T>inline T abs(const T &a){return a>0?a:-a;}
template <typename T>inline T max(const T &a,const T &b){return a<b?b:a;}
template <typename T>inline T min(const T &a,const T &b){return a<b?a:b;}
template <typename T>inline void chmax(T &a,const T &b){(a<b)&&(a=b);}
template <typename T>inline void chmin(T &a,const T &b){(a>b)&&(a=b);}

template <typename T>inline void read(T& x)
{
    register char ch=getchar();
    while(ch<48||ch>57) ch=getchar();
    x=ch&15,ch=getchar();
    while(ch>=48&&ch<=57) x=(((x<<2)+x)<<1)+(ch&15),ch=getchar();
}
template <typename T,typename... Args> inline void read(T& t, Args&... args)
{
    read(t);read(args...);
}

const int N=200005;
int a[N],ans[N],pos;
int cnt[1000005];
int main()
{
	int n;
	ll sum=0;
	read(n);
	for(int i=1;i<=n;++i) read(a[i]),sum+=a[i],++cnt[a[i]];
	for(int i=1;i<=n;++i)
	{
		ll tmp=sum-a[i];
		if(!(tmp&1)&&tmp<=2000000)
		{
			if(cnt[tmp>>1]>=1+(a[i]==tmp>>1))
			{
				ans[++pos]=i;
			}
		}
	}
	printf("%d\n",pos);
	for(int i=1;i<=pos;++i) printf("%d ",ans[i]);
	printf("\n");
	return 0;
}