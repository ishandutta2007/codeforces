#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

const int ML=300100;

struct Tedge { int u,v,p,nx; char c; }lb[ML*2];

int top[ML],tplb;

void CSH() { memset(top,-1,sizeof top); tplb=0; }

void Ins(int u,int v,int p,char c)
{
  int ntop=tplb++;
  
  lb[ntop].v=v; lb[ntop].p=p; lb[ntop].c=c; lb[ntop].nx=top[u];
  
  top[u]=ntop;
}

int op[ML],de[ML],f[ML];

char ans[ML];

int Bfs1(int s)
{
  memset(de,-1,sizeof de);
  memset(ans,'+',sizeof ans);
  
  op[0]=s; de[s]=0;
  
  for (int Head=0,Tail=1; Head<Tail; Head++)
  {
    int u=op[Head];
    
    for (int kb=top[u]; kb!=-1; kb=lb[kb].nx)
    {
      int v=lb[kb].v,p=lb[kb].p,c=lb[kb].c;
      
      if (de[v]!=-1) continue;
      
      ans[p]=c; de[v]=de[u]+1; op[Tail++]=v;
    }
  }
  
  int con=0;
  
  for (int i=0; i<ML; i++) if (de[i]!=-1) con++;
  
  return con;
}

int Bfs2(int s)
{
  memset(de,-1,sizeof de);
  memset(ans,'+',sizeof ans);
  
  op[0]=s; de[s]=0;
  
  for (int Head=0,Tail=1; Head<Tail; Head++)
  {
    int u=op[Head];
    
    for (int kb=top[u]; kb!=-1; kb=lb[kb].nx)
    {
      int v=lb[kb].v,p=lb[kb].p,c=lb[kb].c;
      
      if (f[p]==1 && de[v]==-1) de[v]=de[u]+1,op[Tail++]=v;
      
      if (f[p]==2)
      {
        if (de[v]==-1) ans[p]='+'+'-'-c;
              else ans[p]=c;
      }
    }
  }
  
  int con=0;
  
  for (int i=0; i<ML; i++) if (de[i]!=-1) con++;
  
  return con;
}

int a[ML],b[ML],c[ML];

int main()
{

  int n,m,s; scanf("%d%d%d",&n,&m,&s);
  
  CSH();
  
  for (int i=0; i<m; i++)
  {
    int u,v; scanf("%d%d%d",&f[i],&u,&v);
    
    if (f[i]==1) Ins(u,v,i,'+');
          else Ins(u,v,i,'+'),Ins(v,u,i,'-');
  }
  
  printf("%d\n",Bfs1(s));
  
  for (int i=0; i<m; i++) if (f[i]==2) printf("%c",ans[i]);
  
  printf("\n%d\n",Bfs2(s));
  
  for (int i=0; i<m; i++) if (f[i]==2) printf("%c",ans[i]);
  
  return 0;
}