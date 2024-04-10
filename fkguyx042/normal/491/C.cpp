#include<cstdio>
#include<algorithm>
#include<cstring>

#define N 2000005
#define M 205

using namespace std;
int i,j,m,n,p,k,k1=1,fox[M],que[N*15],st,ed,flow[M],cost[M],vis[M],fa[M],ans;
char c[N],S[N];
int sum[M][M];
struct Node{int ed,before,flow,cost;}s[N];
void add(int p1,int p2,int flow,int cost)
  {  s[++k1].ed=p2; s[k1].flow=flow; s[k1].cost=cost; s[k1].before=fox[p1]; fox[p1]=k1; 
     s[++k1].ed=p1; s[k1].flow=0; s[k1].cost=-cost; s[k1].before=fox[p2]; fox[p2]=k1;
  }
int spfa()
 { int l,r,p,i; l=r=1;
    que[1]=st; memset(flow,-1,sizeof(flow));
      flow[st]=100000000;
      memset(cost,60,sizeof(cost));
      memset(vis,0,sizeof(vis));
      vis[st]=1;
      cost[st]=0;
      for (;l<=r;l++)
       { p=que[l];
         for (i=fox[p];i;i=s[i].before)
           if (s[i].flow)
             if (cost[p]+s[i].cost<cost[s[i].ed])
               {  cost[s[i].ed]=s[i].cost+cost[p];
                   flow[s[i].ed]=min(flow[p],s[i].flow);
                   fa[s[i].ed]=i;
                   if (!vis[s[i].ed]) {vis[s[i].ed]^=1; que[++r]=s[i].ed;
                   }
               }
               vis[p]^=1;
       }
    if (flow[ed]==-1) return 0; return 1;
 }
void doit()
{ int i,p;
      for (i=ed;i!=st;i=s[p^1].ed)
        { p=fa[i];
          s[p].flow-=flow[ed];
          s[p^1].flow+=flow[ed];
        }
}
int get(char x)
{
     if (x>='a') return x-'a';
     return x-'A'+26;
}
char Find(int x)
{
      if (x<26) return 'a'+x;
      return 'A'+x-26;
}
int main()
{
    scanf("%d%d",&n,&k);
    scanf("%s",c); scanf("%s",S);
    for (i=0;i<n;++i) sum[get(c[i])][get(S[i])]++;
    st=2*k; ed=st+1;
    for (i=0;i<k;++i) add(st,i,1,0);
    for (i=0;i<k;++i) add(i+k,ed,1,0);
    for (i=0;i<k;++i)  
       for (j=0;j<k;++j) 
       add(i,j+k,1,-sum[i][j]);
    for (;spfa();) ans+=cost[ed]*flow[ed],doit(); 
    printf("%d\n",-ans);
    for (i=0;i<k;++i)
      for (j=fox[i];j;j=s[j].before) if (s[j].flow==0&&s[j].ed<2*k)
      {
            printf("%c",Find(s[j].ed-k));
            break;
      }
      puts("");      
}