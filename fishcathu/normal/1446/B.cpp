#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N=1E6+10;
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
    char a[19],s=0;
    do a[s++]=x%10|48;while(x/=10);
    do putchar(a[--s]);while(s);
}
char a[5010],b[5010];int dp[5010][5010];
int main()
{
	int n=read(),m=read(),ans=0;
	scanf("%s%s",a+1,b+1);
	for(int i=1;i<=n;++i)for(int j=1;j<=m;++j)
	{
		if(a[i]==b[j])dp[i][j]=dp[i-1][j-1]+2;
		else dp[i][j]=max(max(dp[i][j-1],dp[i-1][j])-1,0);
		ans=max(ans,dp[i][j]);
	}
	write(ans);
}