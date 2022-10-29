#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int i,j,m,n,p,k;
int Ans[1000001];
int main()
{ scanf("%d",&n);
  for (i=1;i<=n;i++)
  { scanf("%d%d",&p,&k);
      if (m+p<=500)
      {  m+=p;
         Ans[i]=1;
      }
	  else {m-=k; Ans[i]=2;}
}
  if (m>500) printf("-1\n");
  else for (i=1;i<=n;i++)
   printf(Ans[i]==1?"A":"G");
}