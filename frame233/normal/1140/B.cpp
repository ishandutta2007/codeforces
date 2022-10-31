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
const int N=105;
char s[N];
int main() 
{
	int T;
	read(T);
	while(T--)
	{
		int n,ans=0x7fffffff;
		read(n);
		scanf("%s",s+1);
		for(int i=1;i<=n;++i)
		{
			if(s[i]=='>')
			{
				chmin(ans,i-1);
			}
			else
			{
				chmin(ans,n-i);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
// <<>>><>>