#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1001;
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
int a[N],f[N][N];
void begin()
{
	const int p=1E9+7;
	for(int i=0;i<N;++i)
	{
		f[i][0]=1;
		for(int j=1;j<=i;++j)
		{
			f[i][j]=(f[i-1][j]+f[i-1][j-1])%p;
		}
	}
}
void solve()
{
	int n=read(),m=read();
	for(int i=1;i<=n;++i)a[i]=read();
	a[n+1]=0;
	sort(a+1,a+1+n,greater<int>());
	int l=0;
	for(int i=m;a[i]==a[m];--i)++l;
	int r=l;
	for(int i=m+1;a[i]==a[m];++i)++r;
	write(f[r][l],'\n');
}
int main()
{
	begin();
	for(int x=read();x--;)
	{
		solve();
	}
}