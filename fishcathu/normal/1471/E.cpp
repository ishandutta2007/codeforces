#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1E6+10;
ll read()
{
    ll a=0;char b=1,c;
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
int n;
int ask(int x)
{
	printf("? ");
	write(x,'\n');
	fflush(stdout);
	return read();
}
int f(int x)
{
	return ((x-1)%n+n)%n+1;
}
int mid(int l,int r)
{
	if(r<l)r+=n;
	return f(l+r>>1);
}
int main()
{
	n=read();
	int k=read(),l,r;
	for(int i=0,j=1;1;++i)
	{
		j=f(j+i);
		int t=ask(j);
		if(t==k)continue;
		if(t<k)l=j,r=f(j+i);
		else r=j,l=f(j-i);
		break;
	}
	while(l!=r)
	{
		int m=mid(l,r);
		int t=ask(m);
		t<k?l=f(m+1):r=m;
	}
	printf("! ");
	write(l,'\n');
}