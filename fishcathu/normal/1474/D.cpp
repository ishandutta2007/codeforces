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
int a[N],l[N],r[N],b[5];
bool checkk(int i)
{
	b[1]=l[i-1];
	b[2]=a[i+1];
	b[3]=a[i];
	b[4]=r[i+2];
	for(int i=1;i<=4;++i)
	{
		b[i]-=b[i-1];
		if(b[i]<0)return 0;
	}
	return !b[4];
}
bool check()
{
	int n=read();
	for(int i=1;i<=n;++i)a[i]=read();
	r[n+1]=0;
	for(int i=1;i<=n;++i)
	{
		if(l[i-1]<0)l[i]=-1;
		else l[i]=a[i]-l[i-1];
	}
	for(int i=n;i>=1;--i)
	{
		if(r[i+1]<0)r[i]=-1;
		else r[i]=a[i]-r[i+1];
	}
	for(int i=1;i<n;++i)
	{
		if(checkk(i))return 1;
	}
	for(int i=1;i<n;++i)if(l[i]<0)return 0;
	if(!l[n])return 1;
	return 0;
}
int main()
{
	for(int x=read();x--;)
	{
		puts(check()?"YES":"NO");
	}
}