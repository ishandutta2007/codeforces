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
    if(x<0)putchar(45),x=-x;
    char a[20],s=0;
    do a[++s]=x%10|48;while(x/=10);
    do putchar(a[s]);while(--s);
    putchar(c);
}
struct st
{
	int u,v;
	bool k;
	bool operator<(const st m)const
	{
		return u<m.u;
	}
}a[N];
int main()
{
	int n=read();
	for(int i=1;i<=n;++i)a[i].u=read();
	ll ans=0;
	for(int i=1;i<=n;++i)
	{
		a[i].v=read();
		if(a[i].u>a[i].v)
		{
			swap(a[i].u,a[i].v);
			a[i].k=1;
		}
		ans+=a[i].v-a[i].u;
	}
	sort(a+1,a+1+n);
	int res=0;
	for(int i=1,mx[2]={0};i<=n;++i)
	{
		res=max(res,min(mx[!a[i].k],a[i].v)-a[i].u);
		mx[a[i].k]=max(mx[a[i].k],a[i].v);
	}
	write(ans-res*2,'\n'); 
}