#include<bits/stdc++.h>
#define ls i<<1
#define rs i<<1|1
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N=1010;
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
    if(x<0)putchar('-'),x=-x;
    char a[20],s=0;
    do a[++s]=x%10|48;while(x/=10);
    do putchar(a[s]);while(--s);
    putchar(c);
}
int a[N],b[N],ans[N];
int main()
{
	int n=read();
	for(int i=1;i<=n;++i)
	{
		a[i]=read();
		b[i]=read();
	}
	while(1)
	{
		int s=0;
		for(int i=1;i<=n;++i)
		{
			if(a[i]+b[i]&1)
			{
				ans[++s]=i;
			}
		}
		if(s&&s!=n)
		{
			write(s,'\n');
			for(int i=1;i<=s;++i)
			{
				write(ans[i],' ');
			}
			return 0;
		}
		if(s==n)
		{
			for(int i=1;i<=n;++i)
			{
				++a[i];
			}
		}
		for(int i=1;i<=n;++i)
		{
			a[i]=a[i]-b[i]>>1;
			b[i]+=a[i];
		}
	}
}