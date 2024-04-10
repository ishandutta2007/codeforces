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
const int N=1E7+1;
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
int a[N],b[N],p[664580];
int ans[N];
void init()
{
	a[1]=1;
	for(int i=2,s=0;i<N;++i)
	{
		if(!a[i])
		{
			a[i]=i+1;
			b[i]=1;
			p[++s]=i;
		}
		for(int j=1;j<=s;++j)
		{
			int t=i*p[j];
			if(t>=N)break;
			if(!(i%p[j]))
			{
				a[t]=a[i]*p[j]+b[i];
				b[t]=b[i];
				break;
			}
			a[t]=a[i]*a[p[j]];
			b[t]=a[i];
		}
	}
	for(int i=N;--i;)
	{
		if(a[i]>=N)continue;
		ans[a[i]]=i;
	}
}
void solve()
{
	int n=read();
	write(ans[n]?ans[n]:-1,'\n');
}
int main()
{
	init();
	for(int x=read();x--;)
	{
		solve();
	}
}