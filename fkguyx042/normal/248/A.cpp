#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int i,j,m,n,p,k;
int l,r;
int main()
{ scanf("%d",&n); int ans=0;
  for (i=1;i<=n;i++)
   { scanf("%d%d",&p,&k);
     if (p) l++;
     if (k) r++;
  }
 if (2*l>n) ans+=n-l;
 else ans+=l;
 if (2*r>n) ans+=n-r; else ans+=r;
 printf("%d\n",ans);
}