#include<algorithm>
#include<iostream>
#include<cstdio>
#define MN 1000
#define Rep(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n,r[MN+5],c[MN+5],m,ans=0;
int main()
{	
	n=read();m=read();
	for(int i=1;i<=m;++i) r[read()]=1,c[read()]=1;
	for(int i=2;n+1-i>i;++i)
	{
		int res=0;
		Rep(a1,0,1-r[i])     Rep(A1,0,a1)
		Rep(a2,0,1-r[n+1-i]) Rep(A2,0,a2)
		Rep(b1,0,1-c[i])     Rep(B1,0,b1)
		Rep(b2,0,1-c[n+1-i]) Rep(B2,0,b2)
		{	
			if(a1&&b1&&A1==B1) continue;
			if(a1&&b2&&(A1^B2)) continue;
			if(a2&&b2&&A2==B2) continue;
			if(a2&&b1&&(A2^B1)) continue;
			res=max(res,a1+a2+b1+b2);
		}
		ans+=res;
	}
	if(n&1) ans+=min(1,2-r[n/2+1]-c[n/2+1]);
	printf("%d\n",ans); 
	return 0;
}