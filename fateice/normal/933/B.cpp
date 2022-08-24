#include<bits/stdc++.h>
#define L long long
using namespace std;
L n;
int m,p,x[1000];
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int i;
	cin>>n>>m;
	while(n)
	  {
       if(n%m>=0)
         {
          x[++p]=n%m;
          n=-n/m;
         }
       else
         {
          x[++p]=m+n%m;
          n=-n/m+1;
         }
      }
    printf("%d\n",p);
    for(i=1;i<=p;i++)
      printf("%d ",x[i]);
	return 0;
}