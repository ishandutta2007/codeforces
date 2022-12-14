#include<iostream>
#include<cstdio>
using namespace std;
inline int read()
{
	int x = 0 , f = 1; char ch = getchar();
	while(ch < '0' || ch > '9'){ if(ch == '-') f = -1;  ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = x * 10 + ch - '0';ch = getchar();}
	return x * f;
}

int n,m,r[17],l[17],f[17][2];
char st[17][105];

int main()
{
	n=read();m=read()+2;
	for(int i=1;i<=n;++i) scanf("%s",st[i]+1);
	for(int i=1;i<=n;++i)
	{
		for(int j=m;j;--j)
			if(st[i][j]=='1') {r[i]=j;break;}
		for(int j=1;j<=m;++j)
			if(st[i][j]=='1') {l[i]=j;break;}
	}
	int i=1;
	for(;i<=n&&!r[i];++i);
	if(i>n) return 0*puts("0");
	f[i][0]=r[i]-1,f[i][1]=m-l[i];
	for(++i;i<=n;++i)
	{
		if(!r[i]) f[i][0]=f[i-1][0]+1,f[i][1]=f[i-1][1]+1;
		else
		{
			f[i][0]=min(f[i-1][0]+2*(r[i]-1)+1,f[i-1][1]+m);
			f[i][1]=min(f[i-1][1]+2*(m-l[i])+1,f[i-1][0]+m);	
		}
	}
	printf("%d\n",min(f[n][0],f[n][1]+m-1));
	return 0;
}