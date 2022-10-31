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

const int N=100005;
int a[55];
inline bool check(int x){return !(x&(x+1));}
int main()
{
	int x;
	read(x);
	int res=0;
	while(!check(x))
	{
		++res;
		int tmp=0;
		for(int i=0;i<=30;++i)
		{
			if((1<<i)<=x&&!(x&(1<<i)))
			{
				tmp=i;
			}
		}
		a[res]=tmp+1;
		x^=(1<<(tmp+1))-1;
		if(check(x)) break;
		++res,++x;
	}
	printf("%d\n",res);
	for(int i=1;i<=res;i+=2) printf("%d ",a[i]);
	printf("\n");
	return 0;
}
//Frame