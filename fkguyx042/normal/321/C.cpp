#include<cstdio>
#include<algorithm>
#include<cstring>

#define N 100005

using namespace std;
int i,j,m,n,p,k,deep[N],x,y,k1;
int Q[N],Re[N],Fa[N],fox[N],vis[N],size[N];
struct Node{int ed,before;}s[N*2];
void add(int x,int y)
{ 
 s[++k1].ed=y; s[k1].before=fox[x]; fox[x]=k1; 
}
int makeroot(int x)
{
     int i,j,l	;
     Q[Q[0]=1]=x; Re[x]=1; Fa[x]=0;
     for (l=1;l<=Q[0];l++)
   {
           p=Q[l];
           for (j=fox[p];j;j=s[j].before)
             if (!vis[s[j].ed]&&!Re[s[j].ed])
             {
                  Re[s[j].ed]=1;
                  Fa[s[j].ed]=p;
                  Q[++Q[0]]=s[j].ed;
             }
   }
   for (i=1;i<=Q[0];i++) Re[Q[i]]=0;
   int Maxn=1000000,Max,id=0;
   for (i=Q[0];i;i--)
{
       Max=0;
       p=Q[i];
       size[p]=1;
       for (j=fox[p];j;j=s[j].before)
         if (!vis[s[j].ed]&&Fa[p]!=s[j].ed)
       {
             size[p]+=size[s[j].ed];
             Max=max(Max,size[s[j].ed]);
       }
       Max=max(Max,Q[0]-size[p]);
       if (Maxn>Max)
       {
          Maxn=Max;
          id=p;
       }
}
return id;
}
void Fen(int x,int Dep)
{
   int root=makeroot(x);
   deep[root]=Dep;
   vis[root]=1;
   int i;	
   for (i=fox[root];i;i=s[i].before)
     if (!vis[s[i].ed]) Fen(s[i].ed,Dep+1);
	}
int main()
{
   scanf("%d",&n);
   for (i=1;i<n;++i) 
   {
     scanf("%d%d",&x,&y);
     add(x,y); add(y,x);
   }
   Fen(1,0);
   for (i=1;i<=n;++i) printf("%c ",deep[i]+'A');
}