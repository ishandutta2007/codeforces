#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
int r,p,k;
int i,j,m,n,x,y;
int main()
{ scanf("%d",&n);
 for (;n--;){ scanf("%d",&m);r=max(r,m); }
 scanf("%d",&n); for (;n--;) { scanf("%d",&m); p=max(p,m);}
 scanf("%d",&n);k=(int)1e9; for(;n--;) { scanf("%d",&m); k=min(k,m);}
 scanf("%d%d",&x,&y); 
  printf("%.10lf\n",sqrt((double)r*r*y*p*1.0/(double)(x*k+y*p)));
}