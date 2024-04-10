#include<bits/stdc++.h>
#define l first
#define r second
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
pii a[N];
int solve()
{
	int n=read(),m=read();
	for(int i=1;i<=n;++i)a[i].r=read();
	for(int i=1;i<=n;++i)a[i].l=read();
	a[n+1].l=0; 
	a[n+1].r=a[n+2].r=0;
	sort(a+1,a+1+n,greater<pii>());
	int k=1;
	while(a[k].l==2)++k;
	int ans=0;
	for(int u=1,v=k,w=0;u<k||v<=n;)
	{
		if(w+a[v].r>=m)
		{
			return ans+1;
		}
		if(u<k&&a[u].r>a[v].r+a[v+1].r)
		{
			w+=a[u].r;
			ans+=2;
			++u;
			if(w>=m)return ans;
		}
		else
		{
			w+=a[v].r;
			++ans;
			++v;
		}
	}
	return -1;
}
int main()
{
	for(int x=read();x--;)
	{
		write(solve(),'\n');
	}
}