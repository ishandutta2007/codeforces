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

int t,n,s,a[30],cnt,sum,ans;

signed main()
{
	t=read();
	while(t--)
	{
		n=read();s=read();
		ans=cnt=sum=0;
		while(n)
		{
			sum+=n%10;
			a[++cnt]=n%10;
			n/=10;
		}
		for(int i=1;i<=cnt&&sum>s;++i)
		{
			sum=sum-a[i]+1;
			a[i+1]++;
			ans+=((int)pow(10,i-1))*(10-a[i]);
			a[i]=0;
		}
		printf("%lld\n",ans);
	}
	return 0;
}