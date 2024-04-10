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
const int N=1010;
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
	int n=read(),m=read();
	for(int i=1;i<=n;++i)scanf("%s",a[i]+1);
	if(m&1)
	{
		puts("YES");
		for(int i=0;i<=m;++i)write((i&1)+1,' ');
		putchar('\n');
		return;
	}
	for(int i=1;i<n;++i)for(int j=i+1;j<=n;++j)
	{
		if(a[i][j]==a[j][i])
		{
			puts("YES");
			for(int k=0;k<=m;++k)write(k&1?i:j,' ');
			putchar('\n');
			return;
		}
	}
	if(n==2)
	{
		puts("NO");
		return;
	}
	puts("YES");
	for(int i=1;i<=n;++i)
	{
		int la=0,lb=0;
		for(int j=1;j<=n;++j)
		{
			if(a[i][j]=='a')la=j;
			if(a[i][j]=='b')lb=j;
		}
		if(!la||!lb)continue;
		bool b=m&2;
		for(int j=0;j<=m;++j)
		{
			int t=j+b;
			write(!(t&1)?i:t&2?la:lb,' ');
		}
		putchar('\n');
		return;
	}
}
int main()
{
	for(int x=read();x--;)
	{
		solve();
	}
}