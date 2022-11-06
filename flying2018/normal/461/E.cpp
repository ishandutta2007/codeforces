#include<iostream>
#include<cstdio>
#include<cstring>
#define N 100010
#define C 4
#define P 16
#define ll long long
using namespace std;
struct matrix{
	ll num[C][C];
	ll* operator [](int a){return num[a];}
	matrix(ll a=0){memset(num,0,sizeof(num));for(int _=0;_<C;_++) for(int __=0;__<C;__++) num[_][__]=a;}
};
int ch[N*P][C],m,cnt,maxd;
ll n;
matrix operator *(matrix a,matrix b)
{
	matrix c(n+1);
	for(int k=0;k<C;k++)
		for(int i=0;i<C;i++)
			for(int j=0;j<C;j++)
			c[i][j]=min(c[i][j],a[i][k]+b[k][j]);
	return c;
}
char str[N];
bool vis[N*P];
int f[C][C][P];
void insert(int p)
{
	int u=0;
	for(int i=p;i<=min(m-1,p+maxd-1);i++)
	{
		int v=str[i]-'A';
		if(!ch[u][v]) ch[u][v]=++cnt;
		u=ch[u][v];
		if(!vis[u]) vis[u]=true,f[str[p]-'A'][v][i-p+1]++;
	}
}
ll ksm(ll a,ll b)
{
	ll r=1;
	for(;b;b>>=1)
	{
		if(b&1) r=r*a;
		a=a*a; 
	}
	return r;
}
matrix ksm(matrix a,ll b)
{
	matrix r=a;
	--b;
	for(;b;b>>=1)
	{
		if(b&1) r=r*a;
		a=a*a; 
	}
	return r;
}
matrix g;
bool check(ll x)
{
	matrix u=ksm(g,x);
	for(int i=0;i<C;i++)
		for(int j=0;j<C;j++)
		if(u[i][j]<n) return true;
	return false;
}
int main()
{
	scanf("%lld%s",&n,str);
	m=strlen(str);
	maxd=min(11,m+1);
	for(int i=0;i<m-1;i++) insert(i);
	for(int i=0;i<C;i++)
		for(int j=0;j<C;j++)
			for(int k=maxd;k>=2;k--)
			if(f[i][j][k]!=ksm(C,k-2)) g[i][j]=k-1;
	ll l=1,r=n;
	while(l<r)
	{
		ll mid=(l+r)>>1;
		if(check(mid)) l=mid+1;
		else r=mid;
	}
	printf("%lld\n",l);
	return 0;
}