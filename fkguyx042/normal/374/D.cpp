#include<cstdio>
#include<algorithm>
#include<cstring>
#define ls (t<<1)
#define rs ((t<<1)+1)
#define mid ((l+r)>>1)
using namespace std;
struct Node{int size,sum;}Tree[4000001];
int sum[1000001],a[1000001],i,j,p,k,m,n,tot=0,Maxn=1000000;
void Delete(int ll,int l,int r,int t)
{ if (l==r) Tree[t].size--;
else { if (Tree[ls].size>=ll) Delete(ll,l,mid,ls);
       else Delete(ll-Tree[ls].size,mid+1,r,rs);
       Tree[t].size=Tree[ls].size+Tree[rs].size;
     }
}
void add(int ll,int c,int l,int r,int t)
{ if (l==r) { Tree[t].size++; Tree[t].sum=c; }
  else { if (ll<=mid) add(ll,c,l,mid,ls);
        else add(ll,c,mid+1,r,rs);
        Tree[t].size=Tree[ls].size+Tree[rs].size;
       }
}
void ask(int ll,int l,int r,int t)
{ if (l==r) printf("%d",Tree[t].sum);
  else { if (Tree[ls].size>=ll) ask(ll,l,mid,ls);
          else ask(ll-Tree[ls].size,mid+1,r,rs);
      }
}
int main()
{ scanf("%d%d",&n,&m);
  for (i=1;i<=m;i++) scanf("%d",&a[i]);
  sort(a+1,a+m+1);
  for (i=1;i<=n;i++)
 {   scanf("%d",&k);
    if(k==-1) {
     for (j=1;j<=m;j++)
     if (Tree[1].size<a[j]) break;
     for (j--;j;j--)
     Delete(a[j],1,Maxn,1); }
    else add(++tot,k,1,Maxn,1);
  }
  if (Tree[1].size) {
  for (i=1;i<=Tree[1].size;i++)
    ask(i,1,Maxn,1); } else printf("Poor stack!\n");
}