#include<bits/stdc++.h>
using namespace std;
int n,a,b;
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int i,j;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	  {
	   scanf("%d",&j);
	   if(j==1)
	     a++;
	   else
	     b++;
	  }
	printf("%d\n",(b>a?a:(b+(a-b)/3)));
	return 0;
}