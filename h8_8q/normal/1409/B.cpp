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

int t,a,b,x,y,n;

inline int getsum(int a,int b,int x,int y,int n);

signed main()
{
	t=read();
	while(t--)
	{
		a=read();b=read();x=read();y=read();n=read();
		printf("%lld\n",min(getsum(a,b,x,y,n),getsum(b,a,y,x,n)));
	}
	return 0;
}

inline int getsum(int a,int b,int x,int y,int n)
{
	int sum=min(a-x,n);
	n-=sum;a-=sum;
	sum=min(b-y,n);
	n-=sum;b-=sum;
	return a*b;
}