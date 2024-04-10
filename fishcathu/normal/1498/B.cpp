#include<bits/stdc++.h>
#define ls i<<1
#define rs i<<1|1
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N=1E6+1;
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
int f[N],a[20],b[20];
void solve()
{
	int n=read(),m=read();
	memset(b,0,sizeof b);
	for(int i=n;i--;)
	{
		++b[f[read()]];
	}
	int ans=0;
	while(n)
	{
		++ans;
		int k=m;
		for(int i=20;i--;)
		{
			while(b[i]&&a[i]<=k)
			{
				k-=a[i];
				--b[i];
				--n;
			}
		}
	}
	write(ans,'\n');
}
int main()
{
	for(int i=1,j=0;i<N;i<<=1,++j)
	{
		f[i]=j;
		a[j]=i;
	}
	for(int x=read();x--;)
	{
		solve();
	}
}