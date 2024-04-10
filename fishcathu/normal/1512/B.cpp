#include<bits/stdc++.h>
#define ls i<<1
#define rs i<<1|1
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N=410;
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
char a[N][N];
void solve()
{
	int n=read();
	for(int i=1;i<=n;++i)scanf("%s",a[i]+1);
	int b=0,c,d,e;
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=n;++j)
		{
			if(a[i][j]=='.')continue;
			if(b)
			{
				d=i;
				e=j;
			}
			else
			{
				b=i;
				c=j;
			}
		}
	}
	if(b==d)
	{
		if(b==1)
		{
			++b;
			++d;
		}
		else
		{
			--b;
			--d;
		}
	}
	else if(c==e)
	{
		if(c==1)
		{
			++c;
			++e;
		}
		else
		{
			--c;
			--e;
		}
	}
	else
	{
		swap(c,e);
	}
	a[b][c]=a[d][e]='*';
	for(int i=1;i<=n;++i)puts(a[i]+1);
}
int main()
{
	for(int x=read();x--;)
	{
		solve();
	}
}