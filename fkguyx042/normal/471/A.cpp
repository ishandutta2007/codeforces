#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int i,j,m,n,p,k,a[11],x;
int main()
{  for (i=1;i<=6;i++)
    scanf("%d",&x),a[x]++;
    for (i=1;i<=9;i++)
     if (a[i]>=4) break;
    if (i==10)
    { printf("Alien\n"); }
    else {
    	a[i]-=4;
    	for (i=1;i<=9;i++) if (a[i]) break;
    	if (a[i]==2) printf("Elephant\n");
    	else printf("Bear\n");
}}