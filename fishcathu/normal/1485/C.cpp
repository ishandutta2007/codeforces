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
void solve()
{
	int a=read(),b=read();
	ll res=0;
	for(int i=1;1;++i)
	{
		int l=min(a/i-1,b),r=min(a/(i+1)-1,b);
		if(r<=i)
		{
			res+=i*1ll*(l-i-1);
			res+=i*1ll*(i+1)>>1;
			break;
		}
		res+=i*1ll*(l-r);
	}
	write(max(res,0ll),'\n');
}
int main()
{
	for(int x=read();x--;)
	{
		solve();
	}
}