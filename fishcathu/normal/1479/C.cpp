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
const int N=500;
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
int u[N],v[N],w[N],f[N],cnt;
void add(int a,int b,int c)
{
	u[++cnt]=a;
	v[cnt]=b;
	w[cnt]=c;
}
int main()
{
	f[1]=f[2]=1;
	for(int i=3;i<=32;++i)f[i]=f[i-1]<<1;
	int x=read()-1,m=read()-x;
	int n=2;
	while(f[n]<m)++n;
	for(int i=2;i<n;++i)for(int j=1;j<i;++j)
	{
		add(j,i,f[j]);
	}
	f[1]=0;
	for(int i=n;--i;)if(f[i]<m)
	{
		add(i,n,m-f[i]+x);
		m-=f[i];
	}
	puts("YES");
	write(n,' ');
	write(cnt,'\n');
	for(int i=1;i<=cnt;++i)
	{
		write(u[i],' ');
		write(v[i],' ');
		write(w[i],'\n');
	}
}