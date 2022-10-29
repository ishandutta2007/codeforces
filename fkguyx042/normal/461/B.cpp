#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int Mo=(int)1e9+7;
int i,j,m,n,p,k,x;
int f[100001][2];
struct Node{int ed,before;}s[100001];
int fox[100001],k1,a[100001];
int power(int x,int y)
{  x%=Mo; int sum=1;
   for (;y;y>>=1) 
    {if (y&1) sum=1ll*sum*x%Mo;
      x=1ll*x*x%Mo;
}
return sum;
}
void add(int p1,int p2)
{ s[++k1].ed=p2; s[k1].before=fox[p1]; fox[p1]=k1; }
void dfs(int x)
{ int sum=1,i;  if (!fox[x]) { f[x][a[x]]=1; return; }
    if (a[x]==1)
{ 
    for (i=fox[x];i;i=s[i].before)
    {  dfs(s[i].ed);
       sum=1ll*(f[s[i].ed][0]+f[s[i].ed][1])%Mo*sum%Mo;
    }
    (f[x][1]+=sum)%=Mo;
}
else {   for (i=fox[x];i;i=s[i].before)
        {   dfs(s[i].ed);
              sum=1ll*(f[s[i].ed][0]+f[s[i].ed][1])%Mo*sum%Mo;
        } f[x][0]=sum;
         for (i=fox[x];i;i=s[i].before)
        (f[x][1]+=1ll*f[s[i].ed][1]*sum%Mo*power(f[s[i].ed][0]+f[s[i].ed][1],Mo-2)%Mo)%=Mo; 
}
}
int main() 
{scanf("%d",&n);
  for (i=1;i<n;i++) scanf("%d",&x),add(x+1,i+1);
  for (i=1;i<=n;i++) scanf("%d",&a[i]);
  dfs(1);
  printf("%d\n",f[1][1]);
}