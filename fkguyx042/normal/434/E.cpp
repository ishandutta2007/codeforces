#include<cstdio>
#include<algorithm>
#include<cstring>
#define Cnt 233333
using namespace std;
 struct Bi{int ed,before;}s[1000001];
 int fox[100005];
 int m,n,p,k,Mo,goal,Go[100001],Back[100001],size[100001],val[100005],inv[100005],Pow[100005],deep[100005];
 int in0[100005],in1[100005],out1[100005],out0[100005];
 int vis[100005],Q[100005],Rt[100005],k1,fa[100005],gg[100005];
 long long ans;
struct Node{
   int fox[Cnt],before[Cnt],ed[Cnt],sum[Cnt]; int tot;
   inline void clear()
   {   
        for (int i=1;i<=tot;i++) 
        {  
            int R=ed[i];
            before[i]=ed[i]=sum[i]=0;
            fox[R%Cnt]=0;
        }
        tot=0;
   }
      inline int ask(int x)
    {  
       int sky=x%Cnt;
       for (int i=fox[sky];i;i=before[i])
     if (ed[i]==x)  return sum[i];
    return 0;
    }
     inline void add(int x)
    {
     int sky=x%Cnt;
     for (int i=fox[sky];i;i=before[i])
     if (ed[i]==x) 
     {   
          sum[i]++;
          return;
     }
     ed[++tot]=x; before[tot]=fox[sky]; fox[sky]=tot; sum[tot]=1;
    }
 }Orz;
 int power(int x,int y)
 {   
    int sum=1;
    for (;y;y>>=1)
  { 
       if (y&1) sum=1ll*sum*x%Mo;
       x=1ll*x*x%Mo;
  }
  return sum;
}
 void add(int x,int y)
 { 
     s[++k1].ed=y; s[k1].before=fox[x]; fox[x]=k1; 
 }
void bfs(int x)
{
   Q[Q[0]=1]=x; Rt[x]=1; Go[x]=Back[x]=val[x]; deep[x]=0;
   for (int i=1;i<=Q[0];i++)
   { 
      int p=Q[i];
      for (int j=fox[p];j;j=s[j].before)
        if (!(vis[s[j].ed]||Rt[s[j].ed]))
        {   
              int A=s[j].ed;
              Go[A]=(1ll*Go[p]*k%Mo+val[A])%Mo;
              deep[A]=deep[p]+1;
              Back[A]=(Back[p]+1ll*val[A]*Pow[deep[A]]%Mo)%Mo;
              Q[++Q[0]]=A;
              Rt[A]=1;
        }
      }
      for (int i=1;i<=Q[0];i++) Rt[Q[i]]=0;
}
void work(int rt,int x,int v)
{   
      Q[Q[0]=1]=x; Rt[x]=1;
      for (int i=1;i<=Q[0];i++)
     { 
           int p=Q[i];
           for (int j=fox[p];j;j=s[j].before)
           {
                  int A=s[j].ed;
                 if (vis[A]||Rt[A]) continue;
                 Rt[A]=1; Q[++Q[0]]=A;
           }
     }
      for (int i=1;i<=Q[0];i++) Orz.add(Back[Q[i]]%Mo);
      for (int i=1;i<=Q[0];i++)
      {    int p=Q[i];
           int Goal=goal;
           (Goal+=1ll*Pow[deep[p]]*val[rt]%Mo)%=Mo;
           Goal=(Goal-Go[p]+Mo)%Mo;
           Goal=1ll*Goal*inv[deep[p]]%Mo;
           gg[Q[i]]=Goal;
           out1[p]+=Orz.ask(Goal)*v;
      }
      Orz.clear();
      for (int i=1;i<=Q[0];i++) 
     { 
        int p=Q[i];
        int Goal=(goal-Go[p]+Mo)%Mo;
        Goal=1ll*Goal*inv[deep[p]]%Mo;
        Orz.add(Goal);
     }
     for (int i=1;i<=Q[0];i++)
     {  
         int p=Q[i];
         int Goal=(Back[p]-val[rt]+Mo)%Mo;
         in1[p]+=Orz.ask(Goal)*v;
     }
     Orz.clear();
     for (int i=1;i<=Q[0];i++) Rt[Q[i]]=0;
}
int getroot(int x)
{ 
   Q[Q[0]=1]=x; Rt[x]=1; fa[x]=0; 
   for (int i=1;i<=Q[0];i++)
  {
       int p=Q[i];
       for (int j=fox[p];j;j=s[j].before)
       { 
            int A=s[j].ed;
             if (vis[A]||Rt[A]) continue;
            Q[++Q[0]]=A;
            fa[A]=p;
            Rt[A]=1;
       }
  }
  int A1=0,A2=1000000;
  for (int i=Q[0];i;i--)
{ 
    int p=Q[i]; size[p]=1; int Max=-1;
    for (int j=fox[p];j;j=s[j].before)
   { 
        int A=s[j].ed;
        if (vis[A]||fa[p]==A) continue;
        Max=max(Max,size[A]);
        size[p]+=size[A];
   }
   Max=max(Max,n-size[p]);
   if (Max<A2)
   { 
     A1=p; A2=Max; 
   }
}
for (int i=1;i<=Q[0];i++) Rt[Q[i]]=0;
return A1;
}
 void Treedp(int root,int dep)
 { 
     int Root=getroot(root);
     bfs(Root);
     vis[Root]=1;
     work(Root,Root,1);
     for (int i=fox[Root];i;i=s[i].before) if (!vis[s[i].ed]) work(Root,s[i].ed,-1);
     for (int i=fox[Root];i;i=s[i].before) if (!vis[s[i].ed]) Treedp(s[i].ed,dep+1);
}
 int main()
 {  
      scanf("%d%d%d%d",&n,&Mo,&k,&goal);
      Pow[0]=1;
      for (int i=1;i<=n;i++) Pow[i]=1ll*Pow[i-1]*k%Mo;
      for (int i=0;i<=n;i++) 
      inv[i]=power(Pow[i],Mo-2);
      for (int i=1;i<=n;i++) scanf("%d",&val[i]);
      for (int i=1;i<n;i++)
      {  
          int u,v;
          scanf("%d%d",&u,&v);
          add(u,v);
          add(v,u);
      }
      Treedp(1,0);
      for (int i=1;i<=n;i++)
  { 
         in0[i]=n-in1[i];
         out0[i]=n-out1[i];
        ans=(ans+2ll*out1[i]*out0[i]);
		ans=(ans+2ll*in1[i]*in0[i]);
		ans=(ans+1ll*in1[i]*out0[i]);
		ans=(ans+1ll*in0[i]*out1[i]); 
   }
    printf("%I64d\n",1ll*n*n*n-ans/2ll);
}