#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
#include<cmath>
#include<queue>
#include<map>
#include<set>

using namespace std;

int read()
{
	int ans=0,f=1;
	char c=getchar();
	while(c>'9'||c<'0'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){ans=ans*10+c-'0';c=getchar();}
	return ans*f;
}

const int N=1e5+5;
int t,n,a[N],b[N],vis[5];

int main()
{
	t=read();
	while(t--)
	{
		memset(vis,0,sizeof(vis));
		n=read();
		for(int i=1;i<=n;++i)
			a[i]=read();
		for(int i=1;i<=n;++i)
			b[i]=read();
		for(int i=1;i<=n;++i)
			if(a[i]!=b[i])
			{
				if(a[i]>b[i]&&!vis[1])
				{
					printf("NO\n");
					goto A;
				}
				if(a[i]<b[i]&&!vis[3])
				{
					printf("NO\n");
					goto A;
				}
				vis[a[i]+2]=1;
			}
			else
				vis[a[i]+2]=1;
		printf("YES\n");
A:;
	}
	return 0;
}