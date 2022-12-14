#include<iostream>
#include<cstdio>
#define MN 50
#define INF 2000000000000000000LL
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
long long f[MN+5],k;int n;
int main()
{
	n=read();f[0]=f[1]=1;cin>>k;
	for(int i=2;i<=n;++i) f[i]=f[i-1]+f[i-2]; 
	for(int i=0;i<n;)
	{
		for(int j=i+1;j<=n;++j)
			if(f[n-j]<k) k-=f[n-j];
			else 
			{
				for(int s=j;s>i;--s) printf("%d ",s);
				i=j;break;
			}
	}
	return 0;
}