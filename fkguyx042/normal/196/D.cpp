#include<cstdio>
#include<algorithm>
#include<cstring>

#define seed 1333
#define Mo 998244353
#define N 400005

#define ls (t<<1)
#define rs ((t<<1)|1)
#define mid ((l+r)>>1)

using namespace std;
int i,j,m,n,p,k,d,pow[N];
char c[N],ch;
struct Node{int size,Zhe,Fan;}tree[4*N],Ans;
void up(Node &a,Node b,Node c)
{
	  a.size=b.size+c.size;
	  a.Zhe=(1ll*b.Zhe*pow[c.size]%Mo+c.Zhe)%Mo;
	  a.Fan=(1ll*c.Fan*pow[b.size]%Mo+b.Fan)%Mo;
}
void build_tree(int l,int r,int t)
{
	 if (l==r) tree[t].size=1,tree[t].Zhe=tree[t].Fan=(int)c[l];
	 else 
	 {
	 	  build_tree(l,mid,ls);
	 	  build_tree(mid+1,r,rs);
	 	  up(tree[t],tree[ls],tree[rs]);
	 }
}
void modify(int ll,int c,int l,int r,int t)
{
	 if (l==r) tree[t].Zhe=tree[t].Fan=c;
	 else 
	 {
	 	  if (ll<=mid) modify(ll,c,l,mid,ls);
	 	  else modify(ll,c,mid+1,r,rs);
	 	  up(tree[t],tree[ls],tree[rs]);
	 }
}
void ask(int ll,int rr,int l,int r,int t)
{
	 if (ll<=l&&r<=rr) up(Ans,Ans,tree[t]);
	 else 
	 {
	 	  if (ll<=mid) ask(ll,rr,l,mid,ls);
	 	  if (rr>mid)  ask(ll,rr,mid+1,r,rs);
	 }
}
int get(int d,int str)
{
      if (str<d) return 0;
      Ans.size=Ans.Zhe=Ans.Fan=0;
      ask(str-d+1,str,1,n,1);
      if (Ans.Zhe==Ans.Fan) return 1;
      return 0;
}
int main()
{
	 scanf("%d",&d);
	 scanf("%s",c);
	 n=strlen(c);
	 for (i=n;i;--i) c[i]=c[i-1];
	 pow[0]=1;
	 for (i=1;i<=n;++i) pow[i]=1ll*pow[i-1]*seed%Mo;
	 build_tree(1,n,1);
	 for (i=1;i<=n;++i) 
	   if (get(d,i)||get(d+1,i)) break;
	 i=min(i,n);
	 for (;i;i--)
  {
  	  for (ch=c[i]+1;ch<='z';++ch)
  	  {
  	  	  modify(i,(int)ch,1,n,1);
  	  	  if (!get(d,i)&&!get(d+1,i)) break;
  	  }
  	  if (ch<='z')
  	  {
  	  	   c[i]=ch;
  	  	   break;
  	  }
  }
    if (i==0) { printf("Impossible\n"); return 0; }
    for (i++;i<=n;++i)
    {
    	  for (ch='a';ch<='z';++ch)
    	  {
    	  	  modify(i,(int)ch,1,n,1);
    	  	  if (!get(d,i)&&!get(d+1,i)) break;
    	  }
    	  c[i]=ch;
    }
    for (i=1;i<=n;++i) printf("%c",c[i]);
}