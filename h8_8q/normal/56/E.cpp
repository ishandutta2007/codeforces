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
int n,ans[N],last[N];

struct Node
{
	int x,h,p;
	bool operator < (const Node &t)const
	{
		return t.x>x;
	}
}a[N];

int main()
{
	n=read();
	for(int i=1;i<=n;++i)
	{
		a[i].x=read();
		a[i].h=read();
		a[i].p=i;
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;++i)
		ans[i]=1;
	for(int i=n-1;i>=1;--i)
	{
		int now=i+1;
		while(now&&a[i].x+a[i].h>a[now].x)
		{
			ans[a[i].p]+=ans[a[now].p];
			now=last[now];
		}
		last[i]=now;
	}
	for(int i=1;i<=n;++i)
		printf("%d ",ans[i]);
	return 0;
}