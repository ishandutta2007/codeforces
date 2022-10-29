#include<cstdio>
#include<algorithm>
#include<cstring>
#define ls (t<<1)
#define rs ((t<<1)+1)
#define mid ((l+r)>>1)
using namespace std;
int i,j,m,n,p,k,tot,k1,fox[200001],x,y,t,val;
struct node{int ed,before;}s[400001];
struct Node{int sum,add;}Tree[800001],tree[800001];
int fa[200001],st[200001],ed[200001],a[200001],deep[200001];
void add(int p1,int p2) {s[++k1].ed=p2; s[k1].before=fox[p1]; fox[p1]=k1; }
void dfs(int x,int ff,int dep)
{  fa[x]=ff;
   st[x]=++tot;
   deep[x]=dep;
   int i;
   for (i=fox[x];i;i=s[i].before)
     if (s[i].ed!=fa[x]) dfs(s[i].ed,x,dep+1);
    ed[x]=tot;
}
void down(int t)
{ Tree[ls].sum+=Tree[t].add;
  Tree[ls].add+=Tree[t].add;
  Tree[rs].add+=Tree[t].add;
  Tree[rs].sum+=Tree[t].add;
  Tree[t].add=0;
}
void update(int ll,int rr,int c,int l,int r,int t)
{  if (ll<=l&&r<=rr) { Tree[t].sum+=c; Tree[t].add+=c; return; }
   down(t);
   if (ll<=mid) update(ll,rr,c,l,mid,ls);
   if (rr>mid) update(ll,rr,c,mid+1,r,rs);
}
void Down(int t)
{ tree[ls].sum+=tree[t].add;
  tree[ls].add+=tree[t].add;
  tree[rs].add+=tree[t].add;
  tree[rs].sum+=tree[t].add;
  tree[t].add=0;
}
void Ask(int ll,int l,int r,int t)
{ if (l==r) printf("%d\n",tree[t].sum);
else { Down(t);
  if (ll<=mid) Ask(ll,l,mid,ls); else Ask(ll,mid+1,r,rs); }
}
void Update(int ll,int rr,int c,int l,int r,int t)
{  if (ll<=l&&r<=rr) { tree[t].sum+=c; tree[t].add+=c; return; }
   Down(t);
   if (ll<=mid) Update(ll,rr,c,l,mid,ls);
   if (rr>mid) Update(ll,rr,c,mid+1,r,rs);
}
void ask(int ll,int l,int r,int t)
{ if (l==r) printf("%d\n",Tree[t].sum);
else { down(t);
  if (ll<=mid) ask(ll,l,mid,ls); else ask(ll,mid+1,r,rs); }
}
int main()
{   scanf("%d%d",&n,&m);
    for (i=1;i<=n;i++) scanf("%d",&a[i]);
    for (i=1;i<n;i++)
    { scanf("%d%d",&x,&y);
      add(x,y); add(y,x);}
dfs(1,0,1);
  for (i=1;i<=n;i++) if (deep[i]&1) update(st[i],st[i],a[i],1,n,1); else Update(st[i],st[i],a[i],1,n,1);
  for (i=1;i<=m;i++) 
  { scanf("%d",&t);
     if (t==1) { scanf("%d%d",&x,&val); if (deep[x]&1) update(st[x],ed[x],val,1,n,1),Update(st[x],ed[x],-val,1,n,1);
     else update(st[x],ed[x],-val,1,n,1),Update(st[x],ed[x],val,1,n,1); }
     else {  scanf("%d",&x); if (deep[x]&1) ask(st[x],1,n,1); else Ask(st[x],1,n,1); }
}
}