#include<bits/stdc++.h>
using namespace std;
int n,x[200010],p,q;
long long k;
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int i,j;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	  {
	   scanf("%d",&x[i]);
	   j=sqrt(x[i])+3;
	   while(j*j>x[i])
	     j--;
	   if(j*j==x[i])
	     {
		  p++;
		  if(!x[i])
		    q++;
		  x[i]=2e9;
		 }
	   else
	     x[i]=min(x[i]-j*j,(j+1)*(j+1)-x[i]);
	  }
	if(p>n/2)
	  printf("%d\n",p-n/2+max(q-n/2,0));
	else
	  {
	   sort(x+1,x+n+1);
	   for(i=1;i<=n/2-p;i++)
	     k+=x[i];
	   cout<<k;
	  }
	return 0;
}