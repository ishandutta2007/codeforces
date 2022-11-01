#include<bits/stdc++.h>
#define ls i<<1
#define rs i<<1|1
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
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
struct st
{
	int id;
	vector<int>v;
	bool operator<(const st m)const
	{
		return v.size()<m.v.size();
	}
}a[N];
int b[N],ans[N];
void solve()
{
	memset(b+1,0,read()<<2);
	int n=read();
	for(int i=1;i<=n;++i)
	{
		a[i].id=i;
		a[i].v.clear();
		for(int j=read();j--;)
		{
			a[i].v.pb(read());
		}
	}
	sort(a+1,a+1+n);
	for(int i=1,k=n+1>>1;i<=n;++i)
	{
		int j=a[i].v.size();
		while(j--&&b[a[i].v[j]]==k);
		if(!~j)
		{
			puts("NO");
			return;
		}
		ans[a[i].id]=a[i].v[j];
		++b[a[i].v[j]];
	}
	puts("YES");
	for(int i=1;i<=n;++i)write(ans[i],' ');
	putchar('\n');
}
int main()
{
	for(int x=read();x--;)
	{
		solve();
	}
}