#include<bits/stdc++.h>
#define ls i<<1
#define rs i<<1|1
#define fi first
#define se second
#define int ll
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
int a[N],b[N];
void solve()
{
	int n=read(),m=read();
	for(int i=1;i<=n;++i)a[i]=read();
	for(int i=1;i<n;++i)b[i]=read();
	int ans=inf;
	for(int i=1,j=0,k=0;i<=n;++i)
	{
		int t=m-k;
		ans=min(ans,t/a[i]+!!(t%a[i])+j);
		t=max(b[i]-k,0LL);
		int d=t/a[i]+!!(t%a[i]);
		j+=d+1;
		k=k+d*a[i]-b[i];
	}
	write(ans,'\n');
}
signed main()
{
	for(int x=read();x--;)
	{
		solve();
	}
}