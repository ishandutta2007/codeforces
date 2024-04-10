#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=3010;
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
int a[N],dp[N][N];
int main()
{
 	for(int x=read();x--;)
 	{
 		int n=read();
 		for(int i=1;i<=n;++i)a[i]=read();
 		for(int i=2;i<=n;++i)
 		{
 			for(int j=i;j<=n;++j)dp[i][j]=1<<30;
 			for(int j=i-1,cnt=0;j>=1;--j)if(j+a[j]>=i)
 			{
 				dp[i][j+a[j]]=min(dp[i][j+a[j]],dp[j][i-1]+cnt++);
			}
			for(int j=i+1;j<=n;++j)dp[i][j]=min(dp[i][j],dp[i][j-1]);
		}
		printf("%d\n",dp[n][n]);
	}
}