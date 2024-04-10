#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <queue>
#include <string>
#include <map>
#include <cstring>
#include <ctime>
#include <vector>
#define inf 1e9
#define ll long long
#define maxn 401000
#define y1 fuck
#define For(i,j,k) for(ll i=j;i<=k;i++)
#define Dow(i,j,k) for(ll i=k;i>=j;i--)
inline ll read(){   ll x=0,f=1;char ch=getchar();   while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}  while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}  return x*f; }
inline void write(ll x){    if (x<0) putchar('-'),x=-x; if (x>=10) write(x/10);   putchar(x%10+'0');  }
inline void writeln(ll x){write(x);puts("");}
inline void write_p(ll x){write(x);putchar(' ');}
using namespace std;
ll n,m,x,y,l[300001],cnt[300001],len,tot,ans[300001];
struct node{ll x,y,ly,v;}p[3000001];
inline ll find(ll x)
{
	ll L=1,R=len,ans=0;
	while(L<=R)
	{
		ll mid=L+R>>1;
		if(l[mid]<=x)	ans=max(mid,ans),L=mid+1;else R=mid-1;	
	}
	return ans;	
}
inline bool cmp(node x,node y){return x.x<y.x;}
int main()
{
	n=read();m=read();
	For(i,1,n)
	{
		x=read();y=read();
		p[++tot].x=x;p[tot].y=y;p[tot].ly=y+m;p[tot].v=1;
		l[tot]=y;
		p[++tot].x=x+m;p[tot].y=y;p[tot].ly=y+m;p[tot].v=-1;
		l[tot]=y+m;
	}
	sort(l+1,l+tot+1);
	len=unique(l+1,l+tot+1)-l-1;
	For(i,1,tot)
	{
		p[i].y=find(p[i].y)+1;
		p[i].ly=find(p[i].ly);
	}
	sort(p+1,p+tot+1,cmp);
	For(i,1,tot)
	{
		For(j,p[i].y,p[i].ly)
		{
			ans[cnt[j]]+=(l[j]-l[j-1])*p[i].x;
			cnt[j]+=p[i].v;
			ans[cnt[j]]-=(l[j]-l[j-1])*p[i].x;
		}
	}
	For(i,1,n)	write_p(ans[i]);
}