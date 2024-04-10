#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int i,j,m,n,p,k,L,R,l,r;
int main()
{ scanf("%d%d%d%d",&l,&r,&L,&R);
  printf("%d ",(l!=L)+(r!=R));
if(abs(l-L)==abs(r-R))
printf("1 ");
else if((R+r+(L-l))%2!=0)
printf("0 ");
else printf("2 ");
printf("%d\n",max(abs(l-L),abs(R-r)));
}