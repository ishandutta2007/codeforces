#include<bits/stdc++.h>
#define MN 1005
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n,gs,pre;
int a[MN];
bool bj[MN],u[MN];

int main()
{
	register int i,j;
	n=read();
	for (i=1;i<=n;++i) a[i]=read();
	for (i=1;i<n;++i) if (a[i+1]-a[i]!=a[2]-a[1]) break;
	if (i==n) return 0*printf("No");
	for (i=2;i<n;++i) if (a[i+1]-a[i]!=a[3]-a[2]) break;
	if (i==n) return 0*printf("Yes");
	u[1]=true;
	for (i=2;i<=n;++i)
	{
		if (u[i]) continue;
		memset(bj,0,sizeof(bj));
		gs=1; bj[1]=true;
		for (j=i;j<=n;++j) if (1LL*(a[j]-a[1])*(i-1)==1LL*(a[i]-a[1])*(j-1)) bj[j]=true,++gs;
		if (n-gs<2) return 0*printf("Yes");
		pre=0;
		for (j=1;j<=n;++j)
		{
			if (!bj[j]) {if (pre&&1LL*(a[j]-a[pre])*(i-1)!=1LL*(a[i]-a[1])*(j-pre)) break; pre=j;}
			else u[j]=true;
		}
		if (j>n) return 0*printf("Yes");
	}
	printf("No");
}