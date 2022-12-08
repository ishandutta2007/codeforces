#include <bits/stdc++.h>
using namespace std;
#define rep(a,b,c) for(int a=b;a<c;++a)
#define debug(x) cerr<<(#x)<<": "<<x<<endl
const int sz = 1e3;

int main()
{
	int n;
	scanf("%d",&n);
	int count=0;
	rep(i,0,n)
	{
		rep(j,0,n)
			if(!((i+j)&1))
				count++;
	}
	printf("%d\n",count);
	rep(i,0,n)
	{
		rep(j,0,n)
			if(!((i+j)&1))
				printf("C");
			else
				printf(".");
		printf("\n");
	}
}