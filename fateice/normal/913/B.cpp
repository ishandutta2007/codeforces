#include<bits/stdc++.h>
using namespace std;
int n,x[1010],y[1010],f[1010];
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int i,j;
	scanf("%d",&n);
	for(i=2;i<=n;i++)
	  {
       scanf("%d",&j);
       x[j]++;
       y[j]++;
       if(y[j]==1)
         x[f[j]]--;
       f[i]=j;
      }
    for(i=1;i<=n;i++)
      if(y[i] && x[i]<3)
        break;
    if(i<=n)
      printf("No\n");
    else
      printf("Yes\n");
	return 0;
}