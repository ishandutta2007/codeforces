#include<bits/stdc++.h>
#define ls i<<1
#define rs i<<1|1
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N=2E5+10;
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
int a[N],n,v[N];
bitset<N>b;
void solve1()
{
	for(int i=1;i<=n;++i)b[i]=0;
	for(int i=1,j=1;i<=n;++i)
	{
		if(a[i]!=a[i-1])
		{
			write(a[i],' ');
			b[a[i]]=1;
		}
		else
		{
			while(b[j])++j;
			write(j,' ');
			b[j]=1;
		}
	}
	putchar('\n');
}
void solve2()
{
	for(int i=1,s=0;i<=n;++i)
	{
		if(a[i]!=a[i-1])
		{
			for(int j=a[i-1]+1;j<a[i];++j)
			{
				v[++s]=j;
			}
			write(a[i],' ');
		}
		else
		{
			write(v[s--],' ');
		}
	}
	putchar('\n');
}
void solve()
{
	n=read();
	for(int i=1;i<=n;++i)a[i]=read();
	solve1();
	solve2();
}
int main()
{
	for(int x=read();x--;)
	{
		solve();
	}
}