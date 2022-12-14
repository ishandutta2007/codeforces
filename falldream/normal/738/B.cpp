#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0'; ch=getchar();}
	return x*f;
} 
int n,m;
int s[1005][1005];
int r[1005][1005];
int c[1005][1005];

int main()
{
   	n=read();m=read();
   	for(int i=1;i<=n;i++)
   	    for(int j=1;j<=m;j++)
   	       s[i][j]=read();
   	for(int i=1;i<=n;i++)
   	   for(int j=1;j<=m;j++)
   	      r[i][j]=r[i][j-1]+s[i][j];
   	for(int i=1;i<=m;i++)
   	   for(int j=1;j<=n;j++)
   	      c[j][i]=c[j-1][i]+s[j][i];
   	int ans=0;
	for(int i=1;i<=n;i++)
   	   for(int j=1;j<=m;j++)
   	   {
	       if(s[i][j]) continue;
		   if(r[i][j]>0) ans++;
		   if(r[i][m]>r[i][j]) ans++;
		   if(c[i][j]>0) ans++;
		   if(c[n][j]>c[i][j]) ans++;
	   }
	printf("%d",ans);
   	return 0;
}