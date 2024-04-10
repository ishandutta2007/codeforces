#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
const int N=1E5+10;
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
int a[N],las[N],ans[N];
vector<int>v[N],_;
void solve()
{
	int n=read(),m=read();
	for(int i=1;i<=n;++i)
	{
		a[i]=read();
		las[i]=0;
		v[i].clear();
	}
	_.clear();
	for(int i=1;i<=n;++i)
	{
		int t=read();
		if(t!=a[i])
		{
			v[t].pb(i);
		}
		las[t]=i;
	}
	for(int i=1;i<=m;++i)
	{
		int t=read();
		if(!las[t])_.pb(i);
		else
		{
			int res=v[t].empty()?las[t]:v[t].back();
			while(!_.empty())
			{
				ans[_.back()]=res;
				_.pop_back();
			}
			ans[i]=res;
			if(!v[t].empty())v[t].pop_back();
		}
	}
	for(int i=1;i<=n;++i)if(!v[i].empty())
	{
		puts("NO");
		return;
	}
	if(!_.empty())
	{
		puts("NO");
		return;
	}
	puts("YES");
	for(int i=1;i<=m;++i)write(ans[i],' ');
	putchar('\n');
}
int main()
{
	for(int x=read();x--;)
	{
		solve();
	}
}