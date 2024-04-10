#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int i,j,m,n,p,k,N,k1,l,r,wcy;
int Tree[100005],B[100005],dis[100005],vis[100005],Re[100005],Q[100005],fa[100005],size[100005],x,y;
struct Node{int ed,before,cost;}s[1000005];
int fox[100005],L[100005],ll,ww,ans[100005];
long long Ans;
void add(int x,int y,int z)
{
       s[++k1].ed=y; s[k1].before=fox[x]; fox[x]=k1; s[k1].cost=z; 
}
int makeroot(int x)
{
       int i,j;
       Q[Q[0]=1]=x;
       Re[x]=1;
       for (l=1;l<=Q[0];l++)
      {
             p=Q[l];
             for (i=fox[p];i;i=s[i].before)
               if (!Re[s[i].ed]&&!vis[s[i].ed])
             { 
                   Re[s[i].ed]=1;
                   fa[s[i].ed]=p;
                   Q[++Q[0]]=s[i].ed;
             }
       }
       int Maxn=1000000,id=0,Max=0;
       for (l=Q[0];l;l--)
      { 
             p=Q[l];
             size[p]=0;
             Max=0;
             for (i=fox[p];i;i=s[i].before)
             {
                     wcy=s[i].ed;
                     if (fa[p]==wcy||vis[wcy]) continue;
                     size[p]+=size[s[i].ed];
                     Max=max(Max,size[s[i].ed]);
             }
             ++size[p];
             Max=max(Max,Q[0]-size[p]);
             if (Maxn>Max)
             { 
                Maxn=Max; id=p;
             }
       }
       for (i=1;i<=Q[0];i++) Re[Q[i]]=0;
       return id;
}
void bfs(int x)
{ 
      int i;
      Q[Q[0]=1]=x;
      dis[x]=0; L[x]=0; Re[x]=1;
      for (l=1;l<=Q[0];l++)
    { 
           p=Q[l];
           for (i=fox[p];i;i=s[i].before)
             if (!vis[s[i].ed]&&!Re[s[i].ed])
           { 
              Re[s[i].ed]=1;
              Q[++Q[0]]=s[i].ed;
              dis[s[i].ed]=dis[p]+1;
              L[s[i].ed]=L[p]+s[i].cost;
            }
    }
    for (i=1;i<=Q[0];i++) Re[Q[i]]=0;
}
int lowbit(int x) { return x&-x;}
inline bool cmp(int a,int b)
{ 
       return L[a]>L[b];
}
void ins(int x,int y)
{ 
       if (x==0) Tree[0]+=y;
      else 
      for (;x<=n;x+=lowbit(x)) Tree[x]+=y;
}
int ask(int x)
{  
      if (x<0) return 0;
      int sm=Tree[0];
      for (;x;x-=lowbit(x)) sm+=Tree[x];
      return sm;
}
void work(int x,int z)
{ 
     int i;
     Q[Q[0]=1]=x;
     Re[x]=1;
     for (l=1;l<=Q[0];l++)
{ 
       p=Q[l];
       for (i=fox[p];i;i=s[i].before)
         if (!vis[s[i].ed]&&!Re[s[i].ed]) 
       { 
             Q[++Q[0]]=s[i].ed;
             Re[s[i].ed]=1;
       }
}
     for (i=1;i<=Q[0];i++) Re[Q[i]]=0;
     sort(Q+1,Q+Q[0]+1,cmp);
     r=Q[0];
     for (i=1;i<=Q[0];i++)
    {  
           while (r>0&&L[Q[r]]+L[Q[i]]<=ww) ins(dis[Q[r]],1),--r;
           ans[Q[i]]+=ask(ll-dis[Q[i]])*z;
     }
    for (i=++r;i<=Q[0];i++) ins(dis[Q[i]],-1);
}
void Fen(int x)
{ 
      int root=makeroot(x);
      bfs(root);
      work(root,1);
      int i;
      vis[root]=1;
      for (i=fox[root];i;i=s[i].before) 
      if (!vis[s[i].ed]) work(s[i].ed,-1);
      for (i=fox[root];i;i=s[i].before)
      if (!vis[s[i].ed]) Fen(s[i].ed);
}
int main()
{ 
     scanf("%d%d%d",&n,&ll,&ww);
     for (i=2;i<=n;i++) 
 {
       scanf("%d%d",&x,&y);
       add(x,i,y),add(i,x,y);
  }
  Fen(1);
  for (i=1;i<=n;i++)  Ans+=ans[i]-1;
  printf("%I64d\n",Ans/2ll);
}