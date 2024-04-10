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
const int N=2E5+10;
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

void solve()
{
	int n=read();
	int mx=read(),a=0,b=0;
	bool c=0,k=0;
	for(int l=mx;--n;)
	{
		int r=read();
		mx=max(mx,r);
		int t=r-l;
		if(t>0)
		{
			if(t!=a)
			{
				a?k=1:a=t;
			}
		}
		else if(t<0)
		{
			if(t!=b)
			{
				b?k=1:b=t;
			}
		}
		else c=1;
		l=r;
	}
	if(k)puts("-1");
	else if(c)puts(a||b?"-1":"0");
	else if(!a||!b)puts("0");
	else
	{
		b=a-b;
		if(mx<b)
		{
			write(b,' ');
			write(a,'\n');
		}
		else puts("-1");
	}
}
int main()
{
	for(int x=read();x--;)
	{
		solve();
	}
}