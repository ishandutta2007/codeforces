#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,a,b,c[N],x,y,c1,c2,s;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&a,&b);
		n=a+b;
		for(int i=0;i<=n;i++)
			c[i]=0;
		x=n/2,y=n-x;
		c1=min(a,x)+min(b,y),c2=max(0,y-a)+max(0,x-b);
		for(int i=c2;i<=c1;i+=2)
			c[n-i]=1;
		swap(x,y);
		c1=min(a,x)+min(b,y),c2=max(0,y-a)+max(0,x-b);
		for(int i=c2;i<=c1;i+=2)
			c[n-i]=1;
		s=0;
		for(int i=0;i<=n;i++)
			s+=(c[i]);
		printf("%d\n",s);
		for(int i=0;i<=n;i++)
			if(c[i])
				printf("%d ",i);
		puts("");
	}
	return 0;
}