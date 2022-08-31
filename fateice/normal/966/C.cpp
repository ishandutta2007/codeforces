#include<bits/stdc++.h>
#define L long long
#define pb push_back
using namespace std;
int n,u[100];
L a[100010],p;
vector<L> x[100],f;
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int i,j;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	  {
	   scanf("%lld",&a[i]);
	   for(j=60;!(a[i]&(1ll<<j));j--);
	   x[j].pb(a[i]);
      }
    do
      {
       for(i=0;i<=60;i++)
         if(!(p&(1ll<<i)) && u[i]<x[i].size())
           {
            p^=x[i][u[i]];
            f.pb(x[i][u[i]]);
            u[i]++;
            break;
           }
      }
    while(i<=60);
    if(f.size()==n)
      {
       printf("Yes\n");
       for(i=0;i<n;i++)
         printf("%lld ",f[i]);
      }
    else
      printf("No\n");
	return 0;
}