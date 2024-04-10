#include<bits/stdc++.h>
#define ls i<<1
#define rs i<<1|1
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N=3E5+10;
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
int f[N],h[N];
int a[N],pre[N];
int n,ans;
void solve()
{
	for(int i=1,mx=0;i<=n;++i)
	{
		pre[i]=pre[i-1]^f[a[i]];
		mx=max(mx,a[i]);
		if(a[i]==1)mx=1;
		if(i>=mx&&(pre[i]^pre[i-mx])==h[mx])
		{
			++ans;
		}
	}
}
int main()
{
	n=read();
	f[1]=1;
	for(int i=2,p=998244353;i<=n;++i)f[i]=f[i-1]*2%p;
	for(int i=1;i<=n;++i)h[i]=h[i-1]^f[i];
	for(int i=1;i<=n;++i)
	{
		a[i]=read();
		if(a[i]==1)--ans;
	}
	solve();
	reverse(a+1,a+1+n);
	solve();
	write(ans,'\n');
}