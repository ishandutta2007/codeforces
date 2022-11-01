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
const int N=110;
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
	ll a[2],b[2];
	int c[2];
	for(int i=0;i<=1;++i)
	{
		a[i]=c[i]=read();
		b[i]=a[i]*n;
	}
	ll ans=b[0]+b[1];
	for(int i=2;i<n;++i)
	{
		int j=i&1,t=read();
		c[j]=min(c[j],t);
		a[j]+=t;
		b[j]=a[j]+c[j]*1LL*(n-1-(i>>1));
		ans=min(ans,b[0]+b[1]);
	}
	write(ans,'\n');
}
int main()
{
	for(int x=read();x--;)
	{
		solve();
	}
}