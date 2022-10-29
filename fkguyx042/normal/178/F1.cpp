#include<cstdio>
#include<algorithm>
#include<cstring>
#include<map>

#define N 1000005
#define M 2005

using namespace std;
char c[M];
int End[N],f[M*2][M],p,tot=1,size[N],i,j,k,K,n,g[M],mp[N][26];
int now,rel[N],T[N],G[M],l;
int main()
{
    scanf("%d%d",&n,&K);
    for (i=1;i<=n;++i)
    {   
         scanf("%s",c);
         int len=strlen(c);
         for (j=0,p=1;j<len;++j)
         {
               int ch=c[j]-'a';
               if (!mp[p][ch]) mp[p][ch]=++tot;
               p=mp[p][ch];
         }
         size[p]++;
    }
    for (i=tot;i;--i) 
   {
          for (j=0,g[0]=0;j<26;++j)
           if (mp[i][j])
            g[++g[0]]=mp[i][j];
          if (size[i]||g[0]>1)
          {
              ++now; rel[i]=now;
              for (j=1;j<=g[0];++j)
                 for (k=1;k<=size[g[j]];++k)
                   f[rel[g[j]]][k]+=T[rel[g[j]]]*k*(k-1)/2;
              for (j=1;j<=g[0];size[i]+=size[g[j]],++j)
              {
                 memset(G,0,sizeof(G));
                for (k=0;k<=size[i];++k)
                  for (l=0;l<=K-k&&l<=size[g[j]];++l)
                   G[k+l]=max(G[k+l],f[now][k]+f[rel[g[j]]][l]);
                  memcpy(f[now],G,sizeof(G));
              }
              for (j=1;j<=size[i];++j) 
                f[now][j]+=j*(j-1)/2;
          }
          else
          {
               rel[i]=rel[g[1]];
               T[rel[i]]++;
               size[i]=size[g[1]];
          }
   }
   printf("%d\n",f[rel[1]][K]+(T[rel[1]]-1)*K*(K-1)/2);      
}