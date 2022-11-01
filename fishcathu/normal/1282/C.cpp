#include<bits/stdc++.h>
#define ls i<<1
#define rs i<<1|1
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
typedef pair<int,bool> pii;
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
pii a[N];
void solve()
{
	int n=read(),m=read(),l=read(),r=read();
	int s=0;
	for(int i=1;i<=n;++i)
	{
		a[i].se=read();
		s+=!a[i].se;
	}
	for(int i=1;i<=n;++i)a[i].fi=read();
	sort(a+1,a+1+n);
	a[++n].fi=m+1;
	int ans=0;
	for(int i=1,j=0;i<=n;++i)
	{
		a[i].fi-=j;
		if(a[i].fi>0)
		{
			int t=min(a[i].fi/l-!(a[i].fi%l),s);
			ans=max(ans,t+i-1);
		}
		j+=a[i].se?r:l;
		if(j>m)break;
		s-=!a[i].se;
	}
	write(ans,'\n');
}
int main()
{
	for(int x=read();x--;)
	{
		solve();
	}
}