#include <bits/stdc++.h>
using namespace std;
#define rep(a,b,c) for(int a=b;a<c;++a)
#define debug(x) cerr<<#x<<": "<<x<<endl;
const int sz = 1e6;

bool arrived[sz];
int main()
{
	int n, x;
	scanf("%d",&n);
	rep(i,0,n)
		arrived[i]=false;
	int i=n-1;
	rep(j,0,n)
	{
		scanf("%d",&x);
		arrived[x-1]=true;
		while(i>=0 && arrived[i])
		{
			printf("%d ",i+1);
			--i;
		}
		printf("\n");
	}
}