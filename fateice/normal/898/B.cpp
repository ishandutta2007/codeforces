#include<bits/stdc++.h>
using namespace std;
int n,a,b;
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int i;
	scanf("%d%d%d",&n,&a,&b);
	for(i=0;i*a<=n;i++)
	  if((n-i*a)%b==0)
	    {
		 printf("YES\n%d %d\n",i,(n-i*a)/b);
		 return 0;
		}
	printf("NO\n");
	return 0;
}