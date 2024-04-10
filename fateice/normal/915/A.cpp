#include<bits/stdc++.h>
#define L long long
using namespace std;
int n,m,p=1e9;
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int i,j;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
	  {
       scanf("%d",&j);
       if(m%j==0)
         p=min(p,m/j);
      }
    printf("%d\n",p);
	return 0;
}