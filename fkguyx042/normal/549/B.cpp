#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int i,j,m,n,p,k,goal[105],Q[105],Ans[105];
char c[105][105];
void del(int x)
{
      int i,j;
      for (i=1;i<=Q[0];++i) 
      if (Q[i]==x)
        {
           for (j=i;j<Q[0];++j) Q[j]=Q[j+1];
           --Q[0];
           return;
        }
}
int main()
{
     scanf("%d",&n);
     for (i=0;i<n;++i) scanf("%s",c[i]);
     for (i=0;i<n;++i) 
     {
         scanf("%d",&goal[i]);
         if (!goal[i]) Q[++Q[0]]=i;
     }
     for (;Q[0];)
    {
          int p=Q[1];
          for (j=0;j<n;++j)
           if (c[p][j]=='1')
          {
               --goal[j];
               if (!goal[j]) Q[++Q[0]]=j;
               if (goal[j]==-1) del(j);
          }
          Ans[++Ans[0]]=p;
    }
    printf("%d\n",Ans[0]);
    for (i=1;i<=Ans[0];++i) printf("%d ",Ans[i]+1);
}