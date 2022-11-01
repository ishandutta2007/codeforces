#include<bits/stdc++.h>
#define ls i<<1
#define rs i<<1|1
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N=1E5+10;
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
    if(x<0)putchar(45),x=-x;
    char a[20],s=0;
    do a[++s]=x%10|48;while(x/=10);
    do putchar(a[s]);while(--s);
    putchar(c);
}
int a[N],n,ans[2]={1,1};
const int p=1E9+7;
void solvee(bool k,int x)
{
	for(int i=1;i<=x;++i)
	{
		ans[k]=ans[k]*1LL*i%p;
	}
}
void solve(int l,int m,int r)
{
	if(l<=1||r<=1)
	{
		solvee(0,n);
		return;
	}
	ans[0]=2;
	solvee(0,l);
	solvee(0,r);
	solvee(0,n);
	solvee(1,n-m);
}
int main()
{
	n=read();
	ll y=0;
	for(int i=1;i<=n;++i)
	{
		a[i]=read();
		y+=a[i];
	}
	if(y%n)
	{
		puts("0");
		return 0;
	}
	y/=n;
	int l=0,m=0,r=0;
	for(int i=1;i<=n;++i)
	{
		if(a[i]<y)++l;
		else if(a[i]==y)++m;
		else ++r;
	}
	solve(l,m,r);
	sort(a+1,a+1+n);
	a[++n]=-1;
	for(int i=1,j=0;i<=n;++i)
	{
		if(a[i]!=a[i-1])
		{
			solvee(1,j);
			j=0;
		}
		++j;
	}
	for(int i=p-2;i;i>>=1)
	{
		if(i&1)ans[0]=ans[0]*1LL*ans[1]%p;
		ans[1]=ans[1]*1LL*ans[1]%p;
	}
	write(ans[0],'\n');
}