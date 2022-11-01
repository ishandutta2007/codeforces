#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=3E5+10;
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
bitset<N>b;
int n;
bool f(int x)
{
	if(x<=1||x>=n)return 0;
	if(a[x]<min(a[x-1],a[x+1]))return 1;
	if(a[x]>max(a[x-1],a[x+1]))return 1;
	return 0;
}
void solve()
{
	n=read();
	for(int i=1;i<=n;++i)a[i]=read();
	int ans=0,mx=0;
	for(int i=2;i<n;++i)
	{
		ans+=b[i]=f(i);
	}
	b[n]=b[n+1]=0;
	for(int i=1;i<=n;++i)
	{
		int mxx=b[i-1]+b[i]+b[i+1],t=a[i];
		a[i]=a[i-1];
		mx=max(mx,mxx-f(i+1));
		a[i]=a[i+1];
		mx=max(mx,mxx-f(i-1));
		a[i]=t;
	}
	write(ans-mx,'\n');
}
int main()
{
	for(int x=read();x--;)
	{
		solve();
	}
}