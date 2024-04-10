#include <bits/stdc++.h>
using namespace std;
#define rep(a,b,c) for(int a=b;a<c;++a)
#define debug(x) cerr<<#x<<": "<<x<<endl
const int sz=1e6;

int main()
{
	int n;
	int a;
	scanf("%d%d",&n,&a);
	int lowest=a, numlo=1, highest=a,numhi=1;
	rep(i,1,n)
	{
		scanf("%d",&a);
		if(a<lowest)
		{
			lowest=a;
			numlo=1;
		}
		else if(a==lowest)
			++numlo;
		if(a>highest)
		{
			highest=a;
			numhi=1;
		}
		else if(a==highest)
			++numhi;
	}
	if(lowest==highest)
		printf("%d\n",n-numhi);
	else
		printf("%d\n",n-numhi-numlo);
}