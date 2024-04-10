#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int i,j,m,n,p,k;
long long A[110],B[110];
char c[200001],c1[200001];
double sum,sum1;
const int Mo=(int)1e9+7;
int main()
{ scanf("%d",&n);
  scanf("%s",&c);
  scanf("%s",&c1);
  for (i=0;i<n;i++)
{  A[c1[i]-'A']+=i+1;
    sum+=1ll*A[c[i]-'A']*(n-i);
    
    sum+=1ll*B[c1[i]-'A']*(n-i);
    B[c[i]-'A']+=i+1;
}
  for (i=1;i<=n;i++)
    sum1+=1ll*(n-i+1)*(n-i+1);
  printf("%.10lf\n",sum/sum1);
}