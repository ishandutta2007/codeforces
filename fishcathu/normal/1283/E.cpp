#include<bits/stdc++.h>
#define ls i<<1
#define rs i<<1|1
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N=2E5+10;
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
int a[N],n;
bitset<N>b;
void solve1()
{
	int res=0;
	for(int i=1;i<=n;++i)
	{
		if(!a[i])continue;
		++res;
		i+=2;
	}
	write(res,' ');
}
void solve2()
{
	for(int i=1;i<=n;++i)
	{
		for(int j=-1;j<=1&&a[i];++j)
		{
			int t=i+j;
			if(b[t])continue;
			b[t]=1;
			--a[i];
		}
	}
	write(b.count(),'\n');
}
int main()
{
	n=read();
	for(int i=n;i--;)
	{
		++a[read()];
	}
	solve1();
	solve2();
}