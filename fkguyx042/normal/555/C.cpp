#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<map>
#include<set>
#include<bitset>
#define mid ((l+r)>>1)
#define ls Treey[t].l
#define rs Treey[t].r
#define Ls Treex[t].l
#define Rs Treex[t].r
using namespace std;
map<int,int>mp;
int n,q,x,y,i,j,tot=1,Tot=1;
char c[5]; 
struct Node{int l,r,sum;} Treex[4000005],Treey[4000005];
void update(int ll,int rr,int c,int l,int r,int t)
{
	  if (ll<=l&&r<=rr) Treey[t].sum=max(Treey[t].sum,c);
	  else 
	  {
	  	  if (ll<=mid) { if (!ls) ls=++tot; update(ll,rr,c,l,mid,ls); }
	  	  if (rr>mid)  { if (!rs) rs=++tot; update(ll,rr,c,mid+1,r,rs); }
	  }
}
void Update(int ll,int rr,int c,int l,int r,int t)
{
	  if (ll<=l&&r<=rr) Treex[t].sum=max(Treex[t].sum,c);
	  else 
	  {
	  	  if (ll<=mid) { if (!Ls) Ls=++Tot; Update(ll,rr,c,l,mid,Ls); }
	  	  if (rr>mid)  { if (!Rs) Rs=++Tot; Update(ll,rr,c,mid+1,r,Rs); }
	  }
}
void ask(int ll,int l,int r,int t)
{
    i=max(i,Treex[t].sum);
    if (l==r) return;
    if (ll<=mid) ask(ll,l,mid,Ls); else ask(ll,mid+1,r,Rs);
}
void Ask(int ll,int l,int r,int t)
{
	 i=max(i,Treey[t].sum);
	 if(l==r) return;
	 if (ll<=mid) Ask(ll,l,mid,ls); else Ask(ll,mid+1,r,rs);
}
int main()
{
	 scanf("%d%d",&n,&q); update(0,n,0,0,n,1); Update(0,n,0,0,n,1);
	 for (;q--;)
	 {
	 	 scanf("%d%d%s",&x,&y,&c);
	 	 if (mp[x]) printf("0\n");
	 	 else 
	 	 {
	 	 	 i=0;
	 	 	 mp[x]=1;
	 	 if (c[0]=='U')
	 	 {
	 	 	 ask(x,0,n,1); printf("%d\n",y-i);
	 	 	 update(i,y,x,0,n,1);
	 	 }
	 	 else 
	 	 {
	 	 	  Ask(y,0,n,1); printf("%d\n",x-i);
	 	 	  Update(i,x,y,0,n,1);
	 	 	  
	     }
	     }
	}
}