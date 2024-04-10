#include <bits/stdc++.h>
using namespace std;
#define rep(a,b,c) for(int a=b;a<c;++a)
#define debug(x) cerr<<(#x)<<": "<<x<<endl
const int sz = 1e6;

int main()
{
	int n, c[sz];
	scanf("%d",&n);
	
	rep(i,0,n)
	{
		int x1,y1,x2,y2;
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		x1%=2;
		if(x1<0)
			x1+=2;
		y1%=2;
		if(y1<0)
			y1+=2;
		c[i] = x1+2*y1;
	}
	printf("YES\n");
	for(int i=0;i<n;i++)
		printf("%d\n",c[i]+1);
}