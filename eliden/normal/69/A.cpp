#include <bits/stdc++.h>
using namespace std;
#define rep(a,b,c) for(int a=b;a<c;++a)
#define debug(x) cerr<<(#x)<<": "<<x<<endl
const int sz = 2e5;

int main()
{
	int n, xs=0, ys=0, zs=0;
	scanf("%d",&n);
	int x,y,z;
	rep(i,0,n)
	{
		scanf("%d%d%d",&x,&y,&z);
		xs+=x, ys+=y, zs+=z;
	}
	if(xs==0 && ys==0 && zs==0)
		printf("YES\n");
	else
		printf("NO\n");
}