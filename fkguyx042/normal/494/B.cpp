#include<cstdio>
#include<algorithm>
#include<cstring>
#define ls (t<<1)
#define rs ((t<<1)+1)
#define mid ((l+r)>>1)
using namespace std;
int i,j,m,n,p,k,x;
const int Mo=(int)1e9+7;
struct Node{int sum,add;} Tree[4000001];
char c[100001],s[100001];
int f[100001],fail[100001],g[100005],All[100005];
void build_tree(int l,int r,int t)
{  Tree[t].add=-1;
   if (l==r) Tree[t].sum=-1;
   else {  build_tree(l,mid,ls); build_tree(mid+1,r,rs); }
}
void down(int t)
{  if (Tree[t].add==-1) return;
   Tree[ls].sum=max(Tree[ls].sum,Tree[t].add);
   Tree[rs].sum=max(Tree[rs].sum,Tree[t].add);
   Tree[ls].add=max(Tree[ls].add,Tree[t].add);
   Tree[rs].add=max(Tree[rs].add,Tree[t].add);
   Tree[t].add=-1;
}
void update(int ll,int rr,int c,int l,int r,int t)
{ if (ll<=l&&r<=rr) Tree[t].add=max(Tree[t].add,c),Tree[t].sum=max(Tree[t].sum,c); 
  else { down(t);
         if (ll<=mid) update(ll,rr,c,l,mid,ls);
         if (rr>mid)  update(ll,rr,c,mid+1,r,rs);
       }
}
int ask(int ll,int l,int r,int t)
{ if (l==r) return Tree[t].sum;
  else { down(t);
         if (ll<=mid) return ask(ll,l,mid,ls);
         else return ask(ll,mid+1,r,rs);
       }
}
int main()
{ scanf("%s",&c);
  scanf("%s",&s);
  int len=strlen(c),Len=strlen(s);
    build_tree(1,len,1);
  for (i=Len;i;i--) s[i]=s[i-1];
  for (i=len;i;i--) c[i]=c[i-1];
  for (i=2,j=0;i<=Len;i++)
  {  while (j&&s[j+1]!=s[i]) j=fail[j];
     if (s[j+1]==s[i]) j++;
     fail[i]=j;
  }
  for (i=1,j=0;i<=len;i++)
 {   while (j&&s[j+1]!=c[i]) j=fail[j];
     if (s[j+1]==c[i]) j++;
     if (j==Len) update(i,len,i-Len,1,len,1),j=fail[j];
 }
  for (i=1;i<=len;i++)
  {  x=ask(i,1,len,1);
	 if (x!=-1) (f[i]+=All[x]+x+1)%=Mo;   
     g[i]=(g[i-1]+f[i])%Mo;
     All[i]=(All[i-1]+g[i])%Mo;
  }
  printf("%d\n",g[len]%Mo);
}