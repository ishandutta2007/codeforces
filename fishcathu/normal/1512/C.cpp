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
char a[N];
int b[2];
void solve()
{
	b[0]=read();
	b[1]=read();
	int n=b[0]+b[1]+1;
	scanf("%s",a+1);
	if(b[0]&1&&b[1]&1)
	{
		puts("-1");
		return;
	}
	for(int i=0;i<=1;++i)
	{
		if(b[i]&1)
		{
			if(a[n>>1]==49-i)
			{
				puts("-1");
				return;
			}
			a[n>>1]=48+i;
			--b[i];
		}
	}
	for(int i=1;i<<1<n;++i)
	{
		if(a[i]=='?'&&a[n-i]=='?')continue;
		int j=a[i]=='?'?n-i:i;
		if(a[n-j]=='?')a[n-j]=a[j];
		else if(a[n-j]!=a[j])
		{
			puts("-1");
			return;
		}
		b[a[j]-48]-=2;
	}
	if(b[0]<0||b[1]<0)
	{
		puts("-1");
		return;
	}
	for(int i=1;i<<1<n;++i)
	{
		if(a[i]!='?')continue;
		bool k=b[1];
		a[i]=a[n-i]=k+48;
		b[k]-=2;
	}
	puts(a+1);
}
int main()
{
	for(int x=read();x--;)
	{
		solve();
	}
}