#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
char s[100005];
int i,j,m,n,p,k;
long long ans=1;
int main()
{ scanf("%s",&s);
  int Len=strlen(s);
  for (i=1;i<=Len;i++)
  if (s[i-1]-'0'+s[i]-'0'==9)
   k++;
   else { if (k>0&&k%2==0) ans*=(k/2+1);
          k=0;
   }
   printf("%I64d\n",ans);
}