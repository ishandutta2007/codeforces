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
const int N=10005;
int a[N],end[N];
int main() 
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%d",&a[i]);
	for(int i=n;i>=1;--i)
	{
		if(a[i]!=i) end[i]=end[a[i]];
		else end[i]=i;
        for(int j=i+1;j<=end[i];++j)
        {
            chmax(end[i],end[j]);
        }
	}
	int pos=1,ans=0;
	while(pos<=n)
	{
		++ans;
		pos=end[pos]+1;
	}
	printf("%d\n",ans);
	return 0;
}