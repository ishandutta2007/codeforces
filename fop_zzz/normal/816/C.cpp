#include <bits/stdc++.h>
#define inf 1e9
#define ll long long
#define For(i,j,k) for(int i=j;i<=k;i++)
#define Dow(i,j,k) for(int i=k;i>=j;i--)
using namespace std;
inline void read(int &tx){   ll x=0,f=1;char ch=getchar();   while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}  while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}  tx=x*f; }
inline void write(ll x){    if (x<0) putchar('-'),x=-x; if (x>=10) write(x/10);   putchar(x%10+'0');  }
inline void writeln(ll x){write(x);puts("");}
int n,m,a[1001][1001],ans1[10000001],ans2[10000001],tot,tot1;
inline void get_l()
{
	For(i,1,n)
	{
		int mi=1e9;
		For(j,1,m)	mi=min(mi,a[i][j]);
		For(j,1,mi)	ans1[++tot]=i;
		For(j,1,m)	a[i][j]-=mi;
	}
}
inline void get_r()
{
	For(i,1,m)
	{
		int mi=1e9;
		For(j,1,n)	mi=min(mi,a[j][i]);
		For(j,1,mi)	ans2[++tot1]=i;
		For(j,1,n)	a[j][i]-=mi;
	}
}
int main()
{
	read(n);read(m);
	For(i,1,n)
		For(j,1,m)	read(a[i][j]);
	if(n<m)	get_l(),get_r();
		else get_r(),get_l();
	For(i,1,n)	For(j,1,m)	if(a[i][j])	{puts("-1");return 0;}
	writeln(tot1+tot);
	For(i,1,tot)	printf("row %d\n",ans1[i]);
	For(i,1,tot1)	printf("col %d\n",ans2[i]);
}