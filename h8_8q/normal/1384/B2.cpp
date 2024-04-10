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
 
const int N=1e6+5;
int t,n,k,l,d[N],now,high,flag;
 
signed main()
{
	t=read();
	while(t--)
	{
		n=read();k=read();l=read();
		for(int i=1;i<=n;++i)
			d[i]=read();
		flag=1;high=k;now=0;
		for(int i=1;i<=n;++i)
		{
			if(d[i]+k<=l) high=k,now=0;
			else
			{
				if(now+d[i]>l){flag=0;break;}
				if(high!=0)
				{
					if(l-d[i]<high) high=l-d[i];
					else high--;
					if(high==0) now=1;
				}
				else now++;
				
			}
		}
		if(flag) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}