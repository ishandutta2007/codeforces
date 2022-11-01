#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
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
void solve()
{
	int n=read();
	for(int i=1;i<=n;++i)a[i]=read();
	sort(a+1,a+1+n,greater<int>());
	ll res=0;
	for(int i=1;i<=n;++i)
	{
		if(i&1&&!(a[i]&1))res+=a[i];
		if(!(i&1)&&a[i]&1)res-=a[i];
	}
	puts(res>0?"Alice":res<0?"Bob":"Tie");
}
int main()
{
	for(int x=read();x--;)
	{
		solve();
	}
}