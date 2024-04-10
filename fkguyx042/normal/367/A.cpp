#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int i,j,m,n,p,k,l,r;
int A[100001][3];
char c[100001];
int main()
{ scanf("%s",&c);
  int Len=strlen(c);
  for (i=0;i<Len;i++)
{   for (j=0;j<3;j++)
   A[i+1][j]=A[i][j];
   A[i+1][c[i]-'x']++;
}
 scanf("%d",&m);
 for (i=1;i<=m;i++)
 { scanf("%d%d",&l,&r);
   if (r-l+1<3) printf("YES\n");
   else 
  {  int x=A[r][0]-A[l-1][0];
     int y=A[r][1]-A[l-1][1];
     int z=A[r][2]-A[l-1][2];
     if (abs(x-y)<=1&&abs(y-z)<=1&&abs(x-z)<=1) printf("YES\n");
     else printf("NO\n");
}
}
}