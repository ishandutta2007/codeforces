#include<cstdio>
#include<algorithm>
#include<cstring>

#define N 1005

using namespace std;
int Ans[N],i,j,m,n,p,k,vis[N],A,B,C,D;
int main()
{
    scanf("%d%d",&n,&m);
    scanf("%d%d%d%d",&A,&B,&C,&D); 
    if (n==4||m<n+1) { puts("-1"); return 0; }
    Ans[1]=A; Ans[2]=C; Ans[n-1]=D; Ans[n]=B;
    vis[A]=vis[B]=vis[C]=vis[D]=1;
    for (i=3;i<=n-2;++i)
    {
        for (j=1;j<=n;++j) if (!vis[j]) break;
        vis[j]=1; Ans[i]=j;
    }
    for (i=1;i<=n;++i) printf("%d ",Ans[i]);
    puts("");
    printf("%d %d ",Ans[2],Ans[1]);
    for (i=3;i<=n-2;++i) printf("%d ",Ans[i]);
    printf("%d %d\n",Ans[n],Ans[n-1]);
}