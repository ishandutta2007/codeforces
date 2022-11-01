#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=201; 
int read()
{
    int a=0;char b=1,c;
    do if((c=getchar())==45)b=-1;while(c<48||c>57);
    do a=(a<<3)+(a<<1)+(c&15);while((c=getchar())>47&&c<58);
    return a*b;
}
void write(int x)
{
    if(x<0)putchar('-'),x=-x;
    char a[10],s=0;
    do a[s++]=x%10|48;while(x/=10);
    do putchar(a[--s]);while(s);
}
int dis[N][N],u[2001],v[2001];
int main()
{
 	int n=read(),m=read(),a1=1,mx=-1;
 	for(int i=1;i<=n;++i)for(int j=1;j<=n;++j)dis[i][j]=n*(i!=j);
 	for(int i=1;i<=m;++i)
 	{
 		u[i]=read();
 		v[i]=read();
 		dis[u[i]][v[i]]=1;
 		dis[v[i]][u[i]]=read()?-1:1;
	}
	for(int i=1;i<=n;++i)for(int j=1;j<=n;++j)for(int k=1;k<=n;++k)
	{
		dis[j][k]=min(dis[j][k],dis[j][i]+dis[i][k]);
	}
	for(int i=1;i<=n;++i)if(dis[i][i]<0)
	{
		puts("NO");
		return 0;
	}
	for(int i=1;i<=n;++i)for(int j=1;j<=n;++j)if(dis[i][j]>mx)mx=dis[i][j],a1=i;
	for(int i=1;i<=m;++i)if(dis[a1][u[i]]==dis[a1][v[i]])
	{
		puts("NO");
		return 0;
	}
	puts("YES");
	printf("%d\n",mx);
	for(int i=1;i<=n;++i)printf("%d ",dis[a1][i]);
}