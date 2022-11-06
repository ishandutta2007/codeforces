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

const int N=1e5+5;
int t,n,p,k,x,y,vis[N],num[N];
char s[N];

signed main()
{
	t=read();
	while(t--)
	{
		n=read();p=read();k=read();
		scanf("%s",s+1);
		x=read();y=read();
		for(int i=1;i<=n;++i)
			vis[i]=0;
		for(int i=n;i>=1;--i)
			if(!vis[i])
			{
				int now=0;
				for(int j=i;j>=p;j-=k)
				{
					now+=(s[j]=='0')*x;
					num[j]=now+(j-p)*y;
					vis[j]=1;
				}
			}
		int ans=1e18;
		for(int i=p;i<=n;++i)
			ans=min(ans,num[i]);
		printf("%lld\n",ans);
	} 
	return 0;
}