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
	int n=read()<<1;
	for(int i=1;i<=n;++i)a[i]=read();
	sort(a+1,a+1+n);
	for(int i=1;i<=n;++i)
	{
		if(a[i]&1)return 0;
		if(i&1^a[i]!=a[i-1])return 0;
	}
	ll res=0;
	for(ll i=3,j=0;i<n;i+=2)
	{
		if((a[i]-a[i-1])%(i-1))return 0;
		j+=(a[i]-a[i-1])/(i>>1);
		res+=j;
	}
	return a[1]>res&&!((a[1]-res)%n);
}
int main()
{
	for(int x=read();x--;)
	{
		puts(check()?"YES":"NO");
	}
}