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
const int N=3E5+10;
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
int h[N];
struct st
{
	int h;
	ll l,r;
}v[N];
int main()
{
	int n=read();
	for(int i=1;i<=n;++i)h[i]=read();
	int s=0;
	for(int i=1;i<=n;++i)
	{
		ll mx=v[s].r;
		while(v[s].h>h[i])
		{
			mx=max(mx,v[s].l);
			--s;
		}
		ll t=mx+read();
		if(s)t=max(t,v[s].r);
		v[++s]={h[i],mx,t};
	}
	write(v[s].r,'\n');
}