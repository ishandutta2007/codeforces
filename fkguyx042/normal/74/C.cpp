#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int m,n,vis[1000001],Last,sky,dec,i,ans;
void dfs(int Now,int LR,int UD,int p)
{   if (p)
    {
    if (LR==0&&vis[Now]) return;
    }
     if (LR==0) vis[Now]=1;
    if (UD==0)
 {   Last=Now;
     sky=(m-Last)/(n-1);
     dec=(m-Last)-sky*(n-1);
     if (sky&1)
    {   Now=n-dec;
        if (Now==1) dfs(Now,LR^1,1,1);
        else dfs(Now,LR^1,0,1);
    }
    else { Now=dec+1;
           if (Now==n) dfs(Now,LR^1,0,1);
           else dfs(Now,LR^1,1,1);
         }
 }
 else {  Last=n-Now+1;  
         sky=(m-Last)/(n-1);
         dec=(m-Last)-sky*(n-1);
         if (sky&1)
        {   Now=dec+1;
            if (Now==n) dfs(Now,LR^1,0,1);
            else dfs(Now,LR^1,1,1);
        }
      else { Now=n-dec;
             if (Now==1) dfs(Now,LR^1,1,1);
             else dfs(Now,LR^1,0,1);
             }
}
}
int main()
{ 
  scanf("%d%d",&n,&m);if (n>m) swap(n,m);
  for (i=1;i<=n;i++)
    if (!vis[i])
    { ans++;
       if (i!=n)
      dfs(i,0,1,0);
        if (i!=1)
       dfs(i,0,0,0);
     }
    printf("%d\n",ans);
}