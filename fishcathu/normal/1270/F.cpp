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
    if(x<0)putchar('-'),x=-x;
    char a[20],s=0;
    do a[++s]=x%10|48;while(x/=10);
    do putchar(a[s]);while(--s);
    putchar(c);
}
char a[N];
int n,m,pre[N],b[N];
int c[N],vis[89400010];
ll ans;
void solve1()
{
	c[0]=m*n-n;
	for(int i=1;i<=n;++i)c[i]=c[i-1]+1;
	for(int i=1;i<=m;++i)
	{
		for(int j=0;j<=n;++j)
		{
			c[j]-=pre[j];
			ans+=vis[c[j]]++;
		}
		for(int j=0;j<=n;++j)
		{
			vis[c[j]]=0;
		}
	}
}
void solve2()
{
	int s=0;
	for(int i=1;i<=n;++i)
	{
		if(a[i])
		{
			b[++s]=i;
		}
	}
	b[s+1]=n+1;
	for(int i=min(m,s);i>=1;--i)
	{
		for(int j=s-i+1;j>=1;--j)
		{
			int k=j+i;
			for(int l=b[k-1]-b[j],r=b[k]-b[j];r<b[k]-b[j-1];++l,++r)
			{
				ans+=max(r/i-max(l/i,m),0);
			}
		}
	}
}
int main()
{
	scanf("%s",a+1);
	n=strlen(a+1);
	for(int i=1;i<=n;++i)
	{
		a[i]-=48;
		pre[i]=pre[i-1]+a[i];
	}
	m=sqrt(n);
	solve1();
	solve2();
	write(ans,'\n'); 
}