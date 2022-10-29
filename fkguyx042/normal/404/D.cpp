#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int f[1000001][7],i,j,m,n,p,k,tot;
const int Mo=(int)(1e9)+7;
char c,s[1000001];
int main()
{  for (c=getchar();c!='\n';c=getchar()) s[++tot]=c;
   f[0][0]=f[0][1]=1;
   for (i=1;i<=tot;i++)
    if (s[i]=='1')
    {  (f[i][0]+=f[i-1][3])%=Mo;
       (f[i][1]+=f[i-1][0])%=Mo;
    }
    else if (s[i]=='2') (f[i][1]+=f[i-1][3])%=Mo;
    else if (s[i]=='0') (f[i][0]+=f[i-1][0])%=Mo;
    else if (s[i]=='*') 
    (f[i][3]+=f[i-1][1])%=Mo,(f[i][3]+=f[i-1][3])%=Mo;
    else 
    {  (f[i][0]+=f[i-1][3])%=Mo;
       (f[i][1]+=f[i-1][0])%=Mo;
       (f[i][1]+=f[i-1][3])%=Mo;
       (f[i][0]+=f[i-1][0])%=Mo;
       (f[i][3]+=f[i-1][1])%=Mo;
       (f[i][3]+=f[i-1][3])%=Mo;
    }
 int ans=0;
  (ans+=f[tot][0])%=Mo;
  (ans+=f[tot][3])%=Mo; 
  printf("%d\n",ans);
}