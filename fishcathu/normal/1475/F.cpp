#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1001;
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
char a[N][N],b[N];
bool check()
{
	int n=read();
	for(int i=1;i<=n;++i)scanf("%s",a[i]+1);
	for(int i=1;i<=n;++i)
	{
		scanf("%s",b+1);
		for(int j=1;j<=n;++j)
		{
			a[i][j]=a[i][j]==b[j];
		}
	}
	for(int j=1;j<=n;++j)if(a[1][j])
	{
		for(int i=2;i<=n;++i)
		{
			a[i][j]=!a[i][j];
		}
	}
	for(int i=2;i<=n;++i)
	{
		for(int j=2;j<=n;++j)
		{
			if(a[i][j]!=a[i][j-1])
			{
				return 0;
			}
		}
	}
	return 1;
}
int main()
{
	for(int x=read();x--;)
	{
		puts(check()?"YES":"NO");
	}
}