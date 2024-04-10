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
struct st
{
	int w,k;
	bool operator<(const st m)const
	{
		return w<m.w;
	}
}a[N];
bool check()
{
	int m=read(),n=read();
	for(int i=1;i<=n;++i)
	{
		a[i].k=read()-1;
		a[i].w=read();
	}
	sort(a+1,a+1+n);
	int t=0;
	for(int i=1;i<=n;++i)
	{
		int j=i-t;
		a[j]=a[i];
		if(a[j].w==a[j-1].w)
		{
			a[j-1].k=-1;
			++t;
		}
	}
	n-=t-1;
	a[n].w=m+1;
	a[n].k=-1;
	t=-1;
	for(int i=1;i<=n;++i)
	{
		if(~a[i].k)
		{
			if(~t)
			{
				if((t+a[i].w-a[i-1].w&1)==a[i].k)
				{
					return 0;
				}
				else t=-1;
			}
			else t=a[i].k;
		}
		else if(~t)return 0;
	}
	return 1;
}
int main()
{
	for(int x=read();x--;)
	{
		puts(check()?"YES":"NO");
	}
}