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
ll a[N];
bool check()
{
	int n=read();
	ll m=read();
	for(int i=1;i<=n;++i)a[i]=read();
	ll res=a[2]-a[1];
	for(int i=3;i<=n;++i)res=__gcd(res,a[i]-a[i-1]);
	return !((m-a[1])%res);
}
int main()
{
	for(int x=read();x--;)
	{
		puts(check()?"YES":"NO");
	}
}