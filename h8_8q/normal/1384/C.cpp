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
int t,n;
char a[N],b[N];

signed main()
{
	t=read();
	while(t--)
	{
		n=read();
		scanf("%s",a+1);
		scanf("%s",b+1);
		int flag=1;
		for(int i=1;i<=n;++i)
			if(a[i]>b[i]) flag=0;
		if(flag==0)
		{
			printf("-1\n");
			continue;
		}
		int ans=0;
		for(int i=1;i<=20;++i)
		{
			flag=0;
			int mmin=1e18;
			for(int j=1;j<=n;++j)
				if(a[j]-'a'+1==i&&a[j]<b[j])
				{
					flag=1;
					mmin=min(mmin,b[j]-'a'+1);
				}
			for(int j=1;j<=n;++j)
				if(a[j]-'a'+1==i&&a[j]<b[j])
					a[j]=mmin+'a'-1;
			ans+=flag;
		}
		printf("%lld\n",ans);
	}
	return 0;
}