#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
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
    char a[10],s=0;
    do a[s++]=x%10|48;while(x/=10);
    do putchar(a[--s]);while(s);
}
char a[510][510];int h[510][510];
int main()
{
	for(int x=read();x--;)
	{
		int n=read(),m=read(),ans=0;
		for(int i=1;i<=n;++i)scanf("%s",a[i]+1);
		for(int i=1;i<=m;++i)for(int j=1;j<=n;++j)
		{
			h[j][i]=a[j][i]=='*'?h[j-1][i]+1:0;
		}		
		for(int i=1;i<=n;++i)
		{
			for(int j=1;j<=m;++j)
			{
				h[i][j]=h[i][j]>h[i][j-1]?h[i][j-1]+1:h[i][j];
			}
			h[i][m+1]=0;
			for(int j=m;j>=1;--j)
			{
				h[i][j]=h[i][j]>h[i][j+1]?h[i][j+1]+1:h[i][j];
				ans+=h[i][j];
			}	
		}
		printf("%d\n",ans);
	}
}