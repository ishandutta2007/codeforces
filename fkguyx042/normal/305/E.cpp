#include<cstdio>
#include<algorithm>
#include<cstring>

#define N 5005

using namespace std;
char c[N];
int n,f[N],i,vis[N],j,blk[N],bl[N]; 
int get()
{
    int ans=0,i,j;
    for (i=0;i<n;)
      if (bl[i])
      {
                  for (j=i;j<n&&bl[j];++j);
                  ans^=f[j-i];
                  i=j; 
      }
      else ++i;   
      return ans;
}
void work()
{
     int i;
     for (i=0;i<n;++i)
       if (blk[i])
       {
            memcpy(bl,blk,sizeof(blk));
            bl[i]=bl[i-1]=bl[i+1]=0;
            if (get()==0) 
            {
                            printf("%d\n",i+1);
                            exit(0);
            }
       }
}
int main()
{
    scanf("%s",c); n=strlen(c);
    f[1]=f[2]=1;
    for (i=3;i<=n;++i)
    {
         memset(vis,0,sizeof(vis));
         for (j=1;j<=i;++j)
         {
             int sum=0;
             if (j>2) sum^=f[j-2];
             if (i-j-1>0) sum^=f[i-j-1];
             vis[sum]=1;
         }
         for (j=0;vis[j];++j);
         f[i]=j;
    }
    for (i=1;i<n-1;++i)
      if (c[i-1]==c[i+1]) blk[i]=1;
    int ans=0;
    for (i=0;i<n;)
      if (blk[i])
      {
                  for (j=i;j<n&&blk[j];++j);
                  ans^=f[j-i];
                  i=j; 
      }
      else ++i;   
    if (!ans) printf("Second\n");
    else printf("First\n"),work();
}