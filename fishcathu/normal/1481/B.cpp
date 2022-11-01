#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
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
int a[N];
int solve()
{
	int n=read(),m=read();
	for(int i=1;i<=n;++i)a[i]=read();
	while(m--)
	{
		int i=1;
		while(i<n&&a[i]>=a[i+1])++i;
		if(i==n)return -1;
		if(!m)return i;
		++a[i];
	}
}
int main()
{
	for(int x=read();x--;)
	{
		write(solve(),'\n');
	}
}