#include<bits/stdc++.h>
#define ls i<<1
#define rs i<<1|1
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
typedef pair<string,int> pii;
const int N=70;
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
int n,m;
bool check0()
{
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
		{
			if(a[i][j]=='P')
			{
				return 0;
			}
		}
	}
	return 1;
}
bool check1()
{
	int i=1;
	while(i<=m&&a[1][i]=='A')++i;
	if(i>m)return 1;
	i=1;
	while(i<=m&&a[n][i]=='A')++i;
	if(i>m)return 1;
	i=1;
	while(i<=n&&a[i][1]=='A')++i;
	if(i>n)return 1;
	i=1;
	while(i<=n&&a[i][m]=='A')++i;
	if(i>n)return 1;
	return 0;
}
bool check2()
{
	if(a[1][1]=='A')return 1;
	if(a[1][m]=='A')return 1;
	if(a[n][1]=='A')return 1;
	if(a[n][m]=='A')return 1;
	for(int i=1;i<=n;++i)
	{
		int j=1;
		while(j<=m&&a[i][j]=='A')
		{
			++j;
		}
		if(j>m)return 1;
	}
	for(int i=1;i<=m;++i)
	{
		int j=1;
		while(j<=n&&a[j][i]=='A')
		{
			++j;
		}
		if(j>n)return 1;
	}
	return 0;
}
bool check3()
{
	for(int i=1;i<=m;++i)
	{
		if(a[1][i]=='A'||a[n][i]=='A')
		{
			return 1;
		}
	}
	for(int i=1;i<=n;++i)
	{
		if(a[i][1]=='A'||a[i][m]=='A')
		{
			return 1;
		}
	}
	return 0;
}
bool check4()
{
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
		{
			if(a[i][j]=='A')
			{
				return 1;
			}
		}
	}
	return 0;
}
void solve()
{
	n=read();
	m=read();
	for(int i=1;i<=n;++i)scanf("%s",a[i]+1);
	if(check0())puts("0");
	else if(check1())puts("1");
	else if(check2())puts("2");
	else if(check3())puts("3");
	else if(check4())puts("4");
	else puts("MORTAL");
}
int main()
{
	for(int x=read();x--;)
	{
		solve();
	}
}