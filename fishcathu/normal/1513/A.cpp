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
int a[N];
void solve()
{
	int n=read(),m=read();
	if(m>n-1>>1)
	{
		puts("-1");
		return;
	}
	memset(a,0,sizeof a);
	for(int i=1,j=n;i<=m;++i)
	{
		a[i<<1]=j--;
	}
	for(int i=1,j=1;i<=n;++i)
	{
		if(!a[i])a[i]=j++;
		write(a[i],' ');
	}
	putchar('\n');
}
int main()
{
	for(int x=read();x--;)
	{
		solve();
	}
}