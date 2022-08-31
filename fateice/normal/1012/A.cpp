#include<bits/stdc++.h>
#define L long long
using namespace std;
int n,x[200010];
L p;
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int i;
	scanf("%d",&n);
	for(i=1;i<=2*n;i++)
	  scanf("%d",&x[i]);
	sort(x+1,x+2*n+1);
	p=(L)(x[n]-x[1])*(x[2*n]-x[n+1]);
	for(i=2;i+n-1<2*n;i++)
	  p=min(p,(L)(x[2*n]-x[1])*(x[i+n-1]-x[i]));
	printf("%lld\n",p);
	return 0;
}