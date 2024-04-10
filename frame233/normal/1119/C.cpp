#include<cstdio>
#include<algorithm>
#define IT std::vector<int>::iterator

typedef long long ll;

int gcd(int a,int b){return (!b)?a:gcd(b,a%b);}
inline int abs(int a){return a>0?a:-a;}
inline int max(int a,int b){return a>b?a:b;}
inline int min(int a,int b){return a<b?a:b;}
inline void swap(int &a,int &b){int tmp=a;a=b,b=tmp;}

ll gcd(ll a,ll b){return (!b)?a:gcd(b,a%b);}
inline ll abs(ll a){return a>0?a:-a;}
inline ll max(ll a,ll b){return a>b?a:b;}
inline ll min(ll a,ll b){return a<b?a:b;}
inline void swap(ll &a,ll &b){ll tmp=a;a=b,b=tmp;}

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

const int N=505;
int a[N][N],t1[N],t2[N];
int main()
{
	int n,m,x;
	read(n,m);
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
		{
			read(a[i][j]);
		}
	}
	int cnt=0;
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
		{
			read(x);
			a[i][j]^=x;
			cnt+=a[i][j];
			t1[i]+=a[i][j];
			t2[j]+=a[i][j];
		}
	}
		for(int i=1;i<=n;++i)
		{
			if(t1[i]&1)
			{
				printf("No\n");
				return 0;
			}
		}
		for(int i=1;i<=m;++i)
		{
			if(t2[i]&1)
			{
				printf("No\n");
				return 0;
			}
		}
	printf("Yes\n");
	return 0;
}
//Dpair AK IOI