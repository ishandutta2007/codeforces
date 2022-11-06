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

int t,n,x,y;

signed main()
{
	t=read();
	while(t--)
	{
		n=read();x=read();y=read();
		int flag=0,sum=0;
		for(int i=0;i<=n-2;++i)
			if((y-x)%(i+1)==0&&x-(n-2-i)*((y-x)/(i+1))>=1)
				flag=(y-x)/(i+1);
			else if((y-x)%(i+1)==0)
				sum=(y-x)/(i+1);
		if(flag)
		{
			for(int i=1,j=y;i<=n;++i,j-=flag)
				printf("%lld ",j);
		}
		else
		{
			int st=x;
			while(st-sum>=1)
				st-=sum;
			for(int i=1;i<=n;++i,st+=sum)
				printf("%lld ",st);
		}
		printf("\n");
	}
	return 0;
}