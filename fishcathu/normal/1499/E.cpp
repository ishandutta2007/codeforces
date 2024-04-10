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
const int N=1010;
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
char a[N],b[N];
int f[N][N][3],n,m;
const int p=998244353;
int dfs(int i,int j,int k)
{
	if(k==3)return 0;
	if(~f[i][j][k])return f[i][j][k];
	f[i][j][k]=0;
	if(k!=1)
	{
		int t=0;
		if(i==n||a[i]==a[i+1])t|=1;
		if(j==m+1||a[i]==b[j])t|=2;
		f[i][j][k]=(f[i][j][k]+1+dfs(i+1,j,t))%p;
	}
	if(k!=2)
	{
		int t=0;
		if(i==n+1||b[j]==a[i])t|=1;
		if(j==m||b[j]==b[j+1])t|=2;
		f[i][j][k]=(f[i][j][k]+1+dfs(i,j+1,t))%p;
	}
	return f[i][j][k];
}
int main()
{
	scanf("%s%s",a+1,b+1);
	n=strlen(a+1);
	m=strlen(b+1);
	int ans=0;
	for(int i=n,t=0;i>=1;--i)
	{
		if(a[i]==a[i+1])t=0;
		++t;
		ans-=t*m;
	}
	for(int i=m,t=0;i>=1;--i)
	{
		if(b[i]==b[i+1])t=0;
		++t;
		ans-=t*n;
	}
	for(int i=1;i<=n+1;++i)
	{
		for(int j=1;j<=m+1;++j)
		{
			for(int k=0;k<3;++k)
			{
				f[i][j][k]=-1;
			}
		}
	}
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
		{
			ans=(ans+dfs(i,j,0))%p;
		}
	}
	write(ans,'\n');
}