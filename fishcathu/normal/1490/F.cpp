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
int a[N];
int b[N];
int r[N];
void solve()
{
	int n=read();
	for(int i=1;i<=n;++i)a[i]=read();
	sort(a+1,a+1+n);
	int m=0;
	for(int i=1;i<=n;++i)
	{
		if(a[i]!=a[i-1])b[++m]=0;
		++b[m];
	}
	sort(b+1,b+1+m);
	b[m+1]=r[m+1]=0;
	for(int i=m;i>=1;--i)r[i]=r[i+1]+b[i];
	int res=1<<30;
	for(int i=1,ress=0;i<=m;)
	{
		int j=i;
		while(b[++j]==b[i]);
		res=min(res,ress+r[j]-b[i]*(m-j+1));
		ress+=b[i]*(j-i);
		i=j;
	}
	write(res,'\n');
}
int main()
{
	for(int x=read();x--;)
	{
		solve();
	}
}