#include<bits/stdc++.h>
#define ls i<<1
#define rs i<<1|1
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N=510;
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
	if(n<=2)
	{
		puts("-1");
		return 0;
	}
	int cnt=0;
	for(int i=4;i<=n;++i)
	{
		if(i&1)
		{
			for(int j=1;j<=i;++j)a[j][i]=++cnt;
			for(int j=i;--j;)a[i][j]=++cnt;
		}
		else
		{
			for(int j=1;j<=i;++j)a[i][j]=++cnt;
			for(int j=i;--j;)a[j][i]=++cnt;
		}
	}
	a[1][1]=++cnt;
	a[1][3]=++cnt;
	a[1][2]=++cnt;
	a[2][1]=++cnt;
	a[2][2]=++cnt;
	a[3][2]=++cnt;
	a[3][3]=++cnt;
	a[3][1]=++cnt;
	a[2][3]=++cnt;
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=n;++j)write(a[i][j],' ');
		putchar('\n');
	}
}