#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <queue>
#include <string>
#include <map>
#include <cstring>
#include <ctime>
#include <bitset>
#include <vector>
#define ll long long
#define N 1020
#define lson x*2
#define rson x*2+1
#define mk make_pair
#define pa pair<int,int>
#define fir first
#define sec second
#define inf 1e9
#define ull unsigned long long  
#define For(i,j,k) for(int i=j;i<=k;i++)
#define Dow(i,j,k) for(int i=k;i>=j;i--)
#define maxn 2000005  
#define base 233  
#define clr(x, c) memset(x, c, sizeof(x))
using namespace std;
inline ll read(){   ll x=0,f=1;char ch=getchar();   while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}  while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}  return x*f; }
inline void write(ll x){    if (x<0) putchar('-'),x=-x; if (x>=10) write(x/10);   putchar(x%10+'0');  }
inline void writeln(ll x){write(x);puts("");};
int n,X,val[500001],x,y,v,tot;
struct node {int p,len,v,t;}a[500001];
inline bool cmp(node x,node y){return x.p!=y.p?x.p<y.p:x.t>y.t;}
int main()
{
	n=read();X=read();
	For(i,0,500000)	val[i]=2e9+7;
	For(i,1,n)
	{
		x=read();y=read();v=read();
		a[++tot].p=x;a[tot].len=y-x+1;a[tot].v=v;a[tot].t=1;
		a[++tot].p=y;a[tot].len=y-x+1;a[tot].v=v;a[tot].t=0;
	}
	sort(a+1,a+tot+1,cmp);
	int ans=2e9+7;
	For(i,1,tot)
	{
		if(a[i].t==1&&val[X-a[i].len]!=2e9+7&&X-a[i].len>0)
			ans=min(ans,a[i].v+val[X-a[i].len]);
		if(a[i].t==0)	val[a[i].len]=min(val[a[i].len],a[i].v);
	}
	if(ans==2e9+7)	puts("-1");else writeln(ans);
}