#include<cstdio>
#include<algorithm>
#include<cstring>
#define ls (t<<1)
#define rs ((t<<1)+1)
#define mid ((l+r)>>1)
using namespace std;
int i,j,m,n,p,k,x,y,tot,k1,K1;
int top[200005],size[200005],son[200005],vis[200005],deep[200005];
int Top[200005],Size[200005],Son[200005],Vis[200005],Deep[200005];
int fox[200005],Fox[200005],st[200005],ed[200005];
int fa[200005],Fa[200005],St[200005],Ed[200005];
int sum[200005],Ans[200005];
struct Node{int ed,before;}s[1000001],S[40000005];
struct Bian{int x,y;}blue[200005],red[200005];
void add(int &x,int y) {s[++k1].ed=y; s[k1].before=x; x=k1; }
int rooted[800005],Rooted[800005];
void Add(int &x,int y){ S[++K1].ed=y; S[K1].before=x; x=K1; }
void ins(int ll,int rr,int l,int r,int t)
{   if (ll<=l&&r<=rr) Add(rooted[t],i);
    else { if (ll<=mid) ins(ll,rr,l,mid,ls);
           if (rr>mid)  ins(ll,rr,mid+1,r,rs);
         }
}
void Ins(int ll,int rr,int l,int r,int t)
{   if (ll<=l&&r<=rr) Add(Rooted[t],i);
    else { if (ll<=mid) Ins(ll,rr,l,mid,ls);
           if (rr>mid)  Ins(ll,rr,mid+1,r,rs);
         }
}
void dfs(int x)
{  int i;
   for (i=fox[x];i;i=s[i].before)
    if (fa[x]!=s[i].ed) 
  { deep[s[i].ed]=deep[x]+1; fa[s[i].ed]=x;  dfs(s[i].ed);
      size[x]+=size[s[i].ed];
      if (!son[x]||size[s[i].ed]>size[son[x]]) son[x]=s[i].ed;
  }
  size[x]++;
}
void dfs1(int x,int y)
{  top[x]=y;
   st[x]=++tot;
   if (son[x]) dfs1(son[x],y);
   int i;
   for (i=fox[x];i;i=s[i].before) 
     if (s[i].ed!=fa[x]&&s[i].ed!=son[x]) dfs1(s[i].ed,s[i].ed);
    ed[x]=tot;
}
void Dfs(int x)
{  int i;
   for (i=Fox[x];i;i=s[i].before)
    if (Fa[x]!=s[i].ed) 
  {   Deep[s[i].ed]=Deep[x]+1;  Fa[s[i].ed]=x;
      Dfs(s[i].ed);
      Size[x]+=Size[s[i].ed];
      if (!Son[x]||Size[s[i].ed]>Size[Son[x]]) Son[x]=s[i].ed;
  }
  Size[x]++;
}
void Dfs1(int x,int y)
{  Top[x]=y;
   St[x]=++tot;
   if (Son[x]) Dfs1(Son[x],y);
   int i;
   for (i=Fox[x];i;i=s[i].before) 
     if (s[i].ed!=Fa[x]&&s[i].ed!=Son[x]) Dfs1(s[i].ed,s[i].ed);
    Ed[x]=tot;
}
void get(int x,int y)
{  for (;Top[x]!=Top[y];)
  {    if (Deep[Top[x]]<Deep[Top[y]]) swap(x,y);
       Ins(St[Top[x]],St[x],1,n,1);
       x=Fa[Top[x]];
  }
  if (Deep[x]<Deep[y]) swap(x,y);
  if (Son[y])
{ 
    y=Son[y];
   if (St[y]<=St[x]) Ins(St[y],St[x],1,n,1);
}
}
void Get(int x,int y)
{  for (;top[x]!=top[y];)
  {    if (deep[top[x]]<deep[top[y]]) swap(x,y);
       ins(st[top[x]],st[x],1,n,1);
       x=fa[top[x]];
  }
  if (deep[x]<deep[y]) swap(x,y);
  if (son[y])
{ 
    y=son[y];
   if (st[y]<=st[x]) ins(st[y],st[x],1,n,1);
}
}
void ask(int ll,int l,int r,int t)
{  int i;
   for (;rooted[t];rooted[t]=S[rooted[t]].before)
     if (!Vis[S[rooted[t]].ed])
    { sum[++sum[0]]=S[rooted[t]].ed;
      Vis[S[rooted[t]].ed]=1;
    }
   if (l==r) return;
  else {
  	   if (ll<=mid) ask(ll,l,mid,ls);
  	   else ask(ll,mid+1,r,rs);
       }
}
void Ask(int ll,int l,int r,int t)
{    for (;Rooted[t];Rooted[t]=S[Rooted[t]].before)
     if (!vis[S[Rooted[t]].ed])
    { sum[++sum[0]]=S[Rooted[t]].ed;
      vis[S[Rooted[t]].ed]=1;
    }
   if (l==r) return;
   else { if (ll<=mid) Ask(ll,l,mid,ls);
          else Ask(ll,mid+1,r,rs);
        }
}
void answer(int x)
{  if (deep[blue[x].x]<deep[blue[x].y])
   ask(st[blue[x].y],1,n,1);
   else ask(st[blue[x].x],1,n,1);
}
void Answer(int x)
{  if (Deep[red[x].x]<Deep[red[x].y])
   Ask(St[red[x].y],1,n,1);
   else Ask(St[red[x].x],1,n,1);
}
int main()
{ scanf("%d",&n);
  for (i=1;i<n;i++) scanf("%d",&x),add(fox[x],i+1),add(fox[i+1],x),blue[i].x=x,blue[i].y=i+1;
  for (i=1;i<n;i++) scanf("%d",&x),add(Fox[x],i+1),add(Fox[i+1],x),red[i].x=x,red[i].y=i+1;
  scanf("%d",&x);
  dfs(1);
  dfs1(1,1);
  tot=0;
  Dfs(1);
  Dfs1(1,1);
  memset(vis,0,sizeof(vis));
  memset(Vis,0,sizeof(Vis)); 
  vis[x]=1;
  for (i=1;i<n;i++)
   if (i!=x) get(blue[i].x,blue[i].y);
  for (i=1;i<n;i++) Get(red[i].x,red[i].y);
  Ans[0]=1; Ans[1]=x;
  for (i=1;Ans[0];i++)
  {    sum[0]=0;
         if (i&1) { 
          printf("Blue\n");
          for (j=1;j<=Ans[0];j++) printf("%d ",Ans[j]);
          
          for (j=1;j<=Ans[0];j++)
           answer(Ans[j]);
       }
    else { printf("Red\n");
           for (j=1;j<=Ans[0];j++) printf("%d ",Ans[j]);
           for (j=1;j<=Ans[0];j++)
            Answer(Ans[j]);
         }
         if (sum[0]>0) sort(sum+1,sum+sum[0]+1);
         for (j=0;j<=sum[0];j++) Ans[j]=sum[j];
         printf("\n");
  }
}