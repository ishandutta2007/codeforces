#include<algorithm>
#include<iostream>
#include<cstdio>
#define MN 5000
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n,a[MN+5],b[MN+5],rk[MN+5],t=-1; 
bool cmp(int x,int y){return a[x]==a[y]?b[x]<b[y]:a[x]<a[y];}
int main()
{
	n=read();
	for(int i=1;i<=n;++i) a[i]=read(),b[i]=read(),rk[i]=i;
	sort(rk+1,rk+n+1,cmp);
	for(int i=1,j;i<=n;i=j+1)
	{
		for(j=i;j<=n&&a[rk[j]]==a[rk[i]];++j);--j;
		if(b[rk[i]]>=t) t=b[rk[j]]; else t=a[rk[i]];
	}
	printf("%d\n",t);
	return 0;
}