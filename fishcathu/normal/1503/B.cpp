#include<bits/stdc++.h>
#define ls i<<1
#define rs i<<1|1
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N=110;
const int inf=1<<30;
ll read()
{
    ll a=0;
    char b=1,c;
    do if((c=getchar())==45)b=-1;while(c<48||c>57);
    do a=(a<<3)+(a<<1)+(c&15);while((c=getchar())>47&&c<58);
    return a*b;
}
void write(ll x,char c)
{
    if(x<0)putchar('-'),x=-x;
    char a[20],s=0;
    do a[++s]=x%10|48;while(x/=10);
    do putchar(a[s]);while(--s);
    putchar(c);
}
int a[N][N];
int main()
{
	int n=read();
	for(int m=n*n,k=0;m--;)
	{
		int t=read();
		int y=1;
		while(y==k||y==t)++y;
		int i=1,j;
		if(k)
		{
			while(i<=n)
			{
				j=1;
				while(j<=n&&a[i][j])
				{
					++j;
				}
				if(j<=n)break;
				++i;
			}
		}
		else
		{
			while(i<=n)
			{
				j=1;
				while(j<=n)
				{
					if(!a[i][j]&&y+i+j&1)break;
					++j;
				}
				if(j<=n)break;
				++i;
			}
			if(i==n&&j>=n-1)k=y;
		}
		a[i][j]=y;
		write(y,' ');
		write(i,' ');
		write(j,'\n');
		fflush(stdout);
	}
	return 0;
}