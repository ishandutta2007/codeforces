#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
#include<cmath>
#include<queue>
#include<map>
#include<set>
#define int long long

using namespace std;

int read()
{
	int ans=0,f=1;
	char c=getchar();
	while(c>'9'||c<'0'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){ans=ans*10+c-'0';c=getchar();}
	return ans*f;
}

const int N=2e5+5;
int t,n,m,k,x[N],y[N],ans,mmax[N];

signed main()
{
	t=read();
	while(t--)
	{
		n=read();k=read();
		for(int i=1;i<=n;++i)
			x[i]=read();
		for(int i=1;i<=n;++i)
			y[i]=read();
		sort(x+1,x+1+n);
		int now=0;ans=0;
		for(int i=1;i<=n;++i)
		{
			int len=upper_bound(x+1,x+1+n,x[i]+k)-x-1;
			now=max(now,mmax[i]);
			ans=max(ans,len-i+1+now);
			mmax[len+1]=max(mmax[len+1],len-i+1);
		}
		for(int i=1;i<=n+1;++i)
			mmax[i]=0;
		printf("%lld\n",ans);
	}
	return 0;
}