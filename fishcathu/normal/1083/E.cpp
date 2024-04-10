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
const int N=1E6+10;
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
	int u,v;
	ll w;
	bool operator<(const st m)const
	{
		return u<m.u;
	}
}a[N];
ll f[N];
int q[N];
double g(int l,int r)
{
	return (f[r]-f[l])*1.0/(a[r].u-a[l].u);
}
int main()
{
	int n=read();
	for(int i=1;i<=n;++i)
	{
		a[i].u=read();
		a[i].v=read();
		a[i].w=read();
	}
	sort(a+1,a+1+n);
	for(int i=1,l=0,r=0;i<=n;++i)
	{
		while(l!=r&&g(q[l],q[l+1])>a[i].v)++l;
		f[i]=f[q[l]]+(a[i].u-a[q[l]].u)*1ll*a[i].v-a[i].w;
		while(l!=r&&g(q[r],i)>g(q[r-1],q[r]))--r;
		q[++r]=i;
	}
	write(*max_element(f+1,f+1+n),'\n');
}