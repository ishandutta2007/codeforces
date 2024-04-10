#include<bits/stdc++.h>
#define L long long
using namespace std;
int n,a,b,p;
inline void pr(int x)
{
    int i;
    printf("%d ",p+x);
    for(i=1;i<x;i++)
      printf("%d ",p+i);
    p+=x;
}
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int i,j,k;
	cin>>n>>a>>b;
	for(i=0;i*a<=n;i++)
	  if((n-i*a)%b==0)
	    break;
	if(i*a<=n)
	  {
       for(j=0;j<i;j++)
         pr(a);
       for(j=0;j<(n-i*a)/b;j++)
         pr(b);
      }
    else
      printf("-1\n");
	return 0;
}