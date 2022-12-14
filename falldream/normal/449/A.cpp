#include<iostream>
#include<cstdio>
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n,m,k;long long ans=0;
int main()
{
	n=read();m=read();k=read();
	if(n+m-2<k) return 0*puts("-1"); 
	for(int i=1,last;i<=n;i=last+1)
	{
		last=n/(n/i);int j=min(last,k+1);
		if(j>=i) ans=max(ans,1LL*(n/j)*(m/(k-(j-1)+1)));
	}
	printf("%lld\n",ans);
	return 0;
}