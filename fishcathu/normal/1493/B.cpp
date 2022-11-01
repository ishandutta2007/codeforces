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
int ff(int x)
{
	if(x<2||x==8)return x;
	if(x==2||x==5)return 7-x;
	return -1;
}
int f(int x)
{
	int l=ff(x/10),r=ff(x%10);
	if(~l&&~r)return r*10+l;
	return -1;
}
void solve()
{
	int n=read(),m=read();
	int l=read(),r=read();
	while(1)
	{
		int u=f(r),v=f(l);
		if(~u&&~v&&u<n&&v<m)break;
		if(++r==m)
		{
			r=0;
			if(++l==n)l=0;
		}
	}
	if(l<10)putchar('0');
	write(l,':');
	if(r<10)putchar('0');
	write(r,'\n');
}
int main()
{
	for(int x=read();x--;)
	{
		solve();
	}
}