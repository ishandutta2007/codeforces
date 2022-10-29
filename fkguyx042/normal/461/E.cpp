 
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int i,j,m,p,k,len,tot;
struct Node{long long B[4][4];}A,Ans;
char c[100005];
long long n,G[2000005][4];
int trans[2000005][4];
void dfs(int x)
{
    int i,v;
    memset(G[x],60,sizeof(G[x]));
    for (i=0;i<4;++i)
    {
        if (!trans[x][i]) G[x][i]=1;
        else
        {
              dfs(v=trans[x][i]);
              for (j=0;j<4;++j) G[x][j]=min(G[x][j],G[v][j]+1);
        }
    }
}
inline Node operator *(Node A,Node B)
{ 
     int i,j,k;
     Node C; memset(C.B,60,sizeof(C));
     for (k=0;k<4;++k)
         for (i=0;i<4;++i)
            for (j=0;j<4;++j)
             C.B[i][j]=min(C.B[i][j],A.B[i][k]+B.B[k][j]);
     return C;
}
bool check(long long Mid)
{
     int i,j;
     for (i=0;i<4;++i)
       for (j=0;j<4;++j)
         A.B[i][j]=G[trans[0][i]][j];
     for (i=0;i<4;++i)
       for (j=0;j<4;++j) Ans.B[i][j]=0;
     for (;Mid;Mid>>=1ll)
     {
             if (Mid&1ll) Ans=Ans*A;
             A=A*A;
     }
     for (i=0;i<4;++i)
       for (j=0;j<4;++j)
         if (Ans.B[i][j]<n) return 0;
     return 1;
}
int main()
{
     scanf("%I64d",&n); scanf("%s",c); 
     len=strlen(c);
         for (i=0;i<len;++i)
              for (k=0,p=0;k<20;++k)
                if (i+k<len)
                {
                      int ch=c[i+k]-'A';
                      if (!trans[p][ch]) trans[p][ch]=++tot;
                      p=trans[p][ch];
                }
     dfs(0);
     long long l=0,r=n,mid=0;
     for (;(l+r)>>1ll!=mid;)
     {
              mid=(l+r)>>1ll;
              if (check(mid)) r=mid;
              else l=mid;
     }
     printf("%I64d\n",r);
}