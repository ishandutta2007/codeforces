#include<cstdio>
#include<algorithm>
#include<cstring>
const int Mo=(int)1e9+7;
using namespace std;
struct Node{int add,sum;}Tree[20001];
int i,j,m,n,p,k,ans,a,b;
int Last[5005],Now[5005];
void Do()
{ int i;
  for (i=n;i;i--)
  Last[i]=(Last[i+1]+Now[i])%Mo;
}
int main()
{ scanf("%d%d%d%d",&n,&a,&b,&k);

  if (a>b) {   n-=b;
      a-=b; }
    else {   a=b-a;
             n=b-1;
        }
     Now[a]=1;
     Do();
     for (i=1;i<=k;i++)
      { for (j=1;j<=n;j++){ Now[j]=(Last[(j/2+1)+(j==1)]-Last[j]+Last[j+1]);
         if  (j==1)  Now[j]-=(-Last[j]+Last[j+1]);
         if (Now[j]<0) Now[j]+=Mo; Now[j]%=Mo;
            }
        Do();
      }
     printf("%d\n",Last[1]);
}