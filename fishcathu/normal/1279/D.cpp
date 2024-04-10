#include<bits/stdc++.h>
#define ls i<<1
#define rs i<<1|1
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N=1E6+1;
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
int ny[N],a[N],b[N];
const int p=998244353;
int f(int x)
{
	int res=1;
	for(int n=p-2;n;n>>=1)
	{
		if(n&1)res=res*1LL*x%p;
		x=x*1LL*x%p;
	}
	return res;
}
int main()
{
	ny[1]=1;
	for(int i=2;i<N;++i)
	{
		ny[i]=(p-p/i)*1LL*ny[p%i]%p;
	}
	int n=read();
	for(int i=1;i<=n;++i)
	{
		int m=read();
		for(int j=m;j--;)
		{
			int t=read();
			a[t]=(a[t]+ny[m])%p;
			++b[t]; 
		}
	}
	int s=0;
	for(int i=1;i<N;++i)
	{
		s=(s+a[i]*1LL*b[i])%p;
	}
	write(s*1LL*f(n*1LL*n%p)%p,'\n');
}