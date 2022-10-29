#include<cstdio>
#include<algorithm>
#include<cstring>
#define mid ((l+r)>>1)
#define ls (t<<1)
#define rs ((t<<1)+1)
using namespace std;
int i,j,m,n,p,k,sum,l,r,L,R;
char c[100001];
struct Node{int sum[27],add;}Tree[400001];
Node Ans;
void up(Node &a,Node b,Node c){ int i;for (i=0;i<26;i++) a.sum[i]=b.sum[i]+c.sum[i]; }
void build_tree(int l,int r,int t)
{   if(l==r) Tree[t].sum[c[l]-'a']++,Tree[t].add=-1;
   else {
            build_tree(l,mid,ls);
            build_tree(mid+1,r,rs);
            up(Tree[t],Tree[ls],Tree[rs]);
            Tree[t].add=-1;
            }
}
void down(int t,int len)
{  if (Tree[t].add==-1) return;
   Tree[ls].add=Tree[rs].add=Tree[t].add;
   int i; for (i=0;i<26;i++) Tree[ls].sum[i]=Tree[rs].sum[i]=0;
   Tree[ls].sum[Tree[t].add]=(len-(len>>1));
   Tree[rs].sum[Tree[t].add]=(len>>1);
   Tree[t].add=-1;
}
void Ask(int ll,int rr,int l,int r,int t)
{   if (ll<=l&&r<=rr) up(Ans,Ans,Tree[t]);
else { down(t,r-l+1);
       if (ll<=mid) Ask(ll,rr,l,mid,ls);
       if (rr>mid) Ask(ll,rr,mid+1,r,rs);
      }
}
void update(int ll,int rr,int c,int l,int r,int t)
{ if (ll<=l&&r<=rr) {
       Tree[t].add=c;
       int i; for(i=0;i<26;i++) Tree[t].sum[i]=0;
       Tree[t].sum[c]=r-l+1;
    }
    else { down(t,r-l+1);
     if (ll<=mid) update(ll,rr,c,l,mid,ls);
     if (rr>mid)  update(ll,rr,c,mid+1,r,rs);
     up(Tree[t],Tree[ls],Tree[rs]);
}
}
void Print(int ll,int l,int r,int t)
{  if(l==r) { 
             int i;
              for (i=0;i<26;i++) if (Tree[t].sum[i]) printf("%c",i+'a');
              } 
  else {  down(t,r-l+1);
         if (ll<=mid) Print(ll,l,mid,ls);
         else Print(ll,mid+1,r,rs);
      }
}
int main()
{ freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  scanf("%d%d",&n,&m);
  scanf("%s",&c);
  for(i=n;i;i--) c[i]=c[i-1];
  build_tree(1,n,1);
  for(;m--;)
{ scanf("%d%d",&l,&r);
  for (i=0;i<26;i++) Ans.sum[i]=0;
  Ask(l,r,1,n,1); sum=0;
  for (i=0;i<26;i++)
  if (Ans.sum[i]&1) sum++;
  if (sum==1&&(r-l+1)%2==1||(r-l+1)%2==0&&sum==0) 
  {  L=l;R=r;
         for (i=0;i<26;i++)
           if (Ans.sum[i]>0&&(Ans.sum[i]&1)==0)
     {   update(L,L+Ans.sum[i]/2-1,i,1,n,1);
         update(R-Ans.sum[i]/2+1,R,i,1,n,1);
         L+=Ans.sum[i]/2;
         R-=Ans.sum[i]/2;
     }
       else if (Ans.sum[i]&1)
     {   if (Ans.sum[i]>1)
        { 
             update(L,L+Ans.sum[i]/2-1,i,1,n,1);
         update(R-Ans.sum[i]/2+1,R,i,1,n,1);
         L+=Ans.sum[i]/2;
         R-=Ans.sum[i]/2;
         Ans.sum[i]=1;
         }
  }
          for (i=0;i<26;i++)
           if (Ans.sum[i]&1)
           update(L,R,i,1,n,1);
}
}
for (i=1;i<=n;i++) Print(i,1,n,1);

}