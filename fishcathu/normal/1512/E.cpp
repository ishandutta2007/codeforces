#include<bits/stdc++.h>
#define ls i<<1
#define rs i<<1|1
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N=510;
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
bitset<N>b;
void solve()
{
	int n=read(),l=read(),r=read(),s=read();
	for(int i=l,j=1;i<=r;++i,++j)
	{
		a[i]=j;
		s-=j;
	}
	if(s<0)
	{
		puts("-1");
		return;
	}
	int k=n-r+l-1;
	if(!k)
	{
		if(s)
		{
			puts("-1");
			return;
		}
		else ++k;
	}
	int u=s/k,v=s%k;
	if(u+!!v>r-l+1)
	{
		puts("-1");
		return;
	}
	for(int i=0;i<u;++i)
	{
		a[r-i]+=k;
	}
	a[r-u]+=v;
	b=0;
	for(int i=l;i<=r;++i)b[a[i]]=1;
	for(int i=1,j=1;i<=n;++i)
	{
		if(i>=l&&i<=r)continue;
		while(b[j])++j;
		a[i]=j;
		b[j]=1;
	}
	for(int i=1;i<=n;++i)
	{
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