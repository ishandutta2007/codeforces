#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int Mo=(int)1e9+7;
int i,j,m,n,p,k,A[26];
char c[100001];
int pow(int x,int y)
{ int sum=1;
  for (;y;y>>=1)
{  if (y&1) sum=1ll*sum*x%Mo;
   x=1ll*x*x%Mo;
}
return sum;
}
int main()
{ scanf("%d",&n);
  scanf("%s",&c);
  for (i=0;i<n;i++) A[c[i]-'A']++;
  sort(A,A+26);
  for (i=24;i>=0;i--) if (A[i]!=A[25]) break;
  printf("%d\n",pow(25-i,n));
}