#include<bits/stdc++.h>
#define ls i<<1
#define rs i<<1|1
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N=60;
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
int a[N];
int main()
{
	int n=read(),m=read();
	for(int i=1;i<=n;++i)
	{
		int t=read();
		if(!a[t])a[t]=i;
	}
	while(m--)
	{
		int t=read();
		write(a[t],' ');
		for(int i=1;i<=50;++i)
		{
			if(a[i]<a[t])
			{
				++a[i];
			}
		}
		a[t]=1;
	}
}