#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
int SG[32],i,m,n,p,k,size,tot;
long long j;
int Now[100001],vis[100001];
int main()
{  scanf("%d",&n);
SG[1]=1;
SG[2]=2;
SG[3]=1;
SG[4]=4;
SG[5]=3;
SG[6]=2;
SG[7]=1;
SG[8]=5;
SG[9]=6;
SG[10]=2;
SG[11]=1;
SG[12]=8;
SG[13]=7;
SG[14]=5;
SG[15]=9;
SG[16]=8;
SG[17]=7;
SG[18]=3;
SG[19]=4;
SG[20]=7;
SG[21]=4;
SG[22]=2;
SG[23]=1;
SG[24]=10;
SG[25]=9;
SG[26]=3;
SG[27]=6;
SG[28]=11;
SG[29]=12;
SG[30]=14;
  Now[++tot]=1; size++;
for (i=2;i<=(int)sqrt(n);i++)
  if (!vis[i])
  {  Now[++tot]=1;
      for (j=i*i;j<=n;j*=i)
     { Now[tot]++;
       if (j<=(int)sqrt(n)) vis[j]=1;
     }
     size+=Now[tot];
}
int ans=(n-size)&1;
for (i=1;i<=tot;i++) ans^=SG[Now[i]];
if (ans) printf("Vasya\n");
else printf("Petya\n");
}