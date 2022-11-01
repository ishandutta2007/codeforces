#include<bits/stdc++.h>
#define ls i<<1
#define rs i<<1|1
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N=1E5+10;
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
int ans[N],a[N];
const int p=1E5;
ll f(ll x)
{
	return x/p+!!(x%p);
}
int main()
{
	int n=read(),m=read();
	memset(ans+1,-1,m<<2);
	for(int j=1;j<=n;++j)
	{
		memset(a,0,sizeof a);
		bool op=read()-1;
		ll x=read();
		int y=read();
		if(op)
		{
			for(int i=0;i<m;++i)
			{
				if(!~ans[i]||a[i]==y)continue;
				ll t=f(i*x);
				if(t>m||~ans[t])continue;
				ans[t]=j;
				a[t]=a[i]+1;
			}
		}
		else
		{
			for(int i=0;i<m;++i)
			{
				if(!~ans[i]||a[i]==y)continue;
				ll t=f(i*1LL*p+x);
				if(t>m||~ans[t])continue;
				ans[t]=j;
				a[t]=a[i]+1;
			}
		}
	}
	for(int i=1;i<=m;++i)write(ans[i],' ');
}