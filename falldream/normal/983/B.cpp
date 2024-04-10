#include<bits/stdc++.h>
#define MN 5000
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int f[MN+5][MN+5],n,Q,mx[MN+5][MN+5];
int main()
{
	n=read();
	for(int i=1;i<=n;++i) f[i][i]=mx[i][i]=read();
	for(int i=n;i;--i) for(int j=i+1;j<=n;++j)
		f[i][j]=f[i][j-1]^f[i+1][j],mx[i][j]=max(f[i][j],max(mx[i+1][j],mx[i][j-1]));
	for(int Q=read(),l,r;Q--;) l=read(),r=read(),printf("%d\n",mx[l][r]);
	return 0;
}