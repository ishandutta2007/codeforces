#include<cstdio>
#include<cstring>
#include<algorithm>
const int N=201;
int read() 
{ 	
    int a=0;char b=1,c; 
    do if((c=getchar())==45)b=-1;while(!(c&16)); 
    do a=(a<<3)+(a<<1)+(c&15);while((c=getchar())&16); 
    return a*b; 
} 
void write(int x) 
{
    if(x<0)putchar('-'),x=-x; 
    char a[10],s=0; 
    do a[s++]=x%10|48;while(x/=10); 
    do putchar(a[--s]);while(s);
}
int a[N],dp[N][N<<1];
int main()
{
	for(int x=read();x--;)
	{
		int n=read();
		for(int i=1;i<=n;++i)a[i]=read();
		std::sort(a+1,a+1+n),memset(dp,0x7f,sizeof dp),dp[0][0]=0;
		for(int i=0;i<=n;++i)for(int j=0;j<n<<1;++j)
		{
			if(dp[i][j]<dp[i][j+1])dp[i][j+1]=dp[i][j];
			if(i!=n&&j>=i)dp[i+1][j+1]=dp[i][j]+(a[i+1]>j+1?a[i+1]-j-1:j+1-a[i+1]);
		}
		write(dp[n][n<<1]),putchar('\n');
	}
	return 0;
}