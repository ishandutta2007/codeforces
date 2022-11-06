#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<string>
#include<vector>
#include<bitset>
#include<cmath>
#include<queue>
#include<map>
#include<set>

#define int long long
#define mid ((l+r)>>1)
#define lowbit(x) (x&(-x))
#define max Max
#define min Min
#define abs Abs

using namespace std;

inline int read()
{
	int res=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){res=res*10+c-'0';c=getchar();}
	return res*f;
}

template<typename T,typename TT> inline T Max(T a,TT b){return a>b?a:b;}
template<typename T,typename TT> inline T Min(T a,TT b){return a>b?b:a;}
template<typename T> inline T Abs(T x){return x<0?-x:x;}

const int N=105;
int t,n,m,a[N];
char s[N*2];

signed main()
{
	t=read();
	while(t--)
	{
		n=read();m=0;
		for(int i=1;i<=n;++i)
			a[i]=read(),m=max(m,a[i]);
		m+=1;
		for(int i=1;i<=m;++i)
			s[i]='a'+(i-1)%26;
		puts(s+1);
		for(int i=1;i<=n;++i)
		{
			for(int j=a[i]+1;j<=m;++j)
			{
				s[j]++;
				if(s[j]>'z') s[j]='a';
			}
			puts(s+1);
		}
	}
	return 0;
}