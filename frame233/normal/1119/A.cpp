#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
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

inline int read()
{
    register char ch=getchar();
    while(ch<48||ch>57) ch=getchar();
    register int x=ch&15;
	ch=getchar();
    while(ch>=48&&ch<=57) x=(((x<<2)+x)<<1)+(ch&15),ch=getchar();
    return x;
}
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

const int N=300005;
int a[N],col[N];
int main()
{
	int n;
	int ans=0;
	read(n);
	for(int i=1;i<=n;++i)
	{
		read(a[i]);
		if(i==1||a[i-1]==a[i])
		{
			++col[a[i]];
			ans=max(ans,i-col[a[i]]-1);
		}
		else
		{
			ans=max(ans,i-col[a[i]]-1);
			a[i]=0;
		}
	}
	printf("%d\n",ans);
	return 0;
}
//Dpair AK IOI