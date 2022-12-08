#include <bits/stdc++.h>
using namespace std;
#define rep(a,b,c) for(int a=b;a<c;++a)
#define debug(x) cerr<<(#x)<<": "<<x<<endl
const int sz = 1e6;
int n, m, a[sz], up[sz], down[sz];
int main()
{
	scanf("%d%d",&n,&m);
	rep(i,0,n)
		scanf("%d",&a[i]);
	up[n-1] = 1;
	down[0] = 1;
	rep(i,1,n)
	{
		if(a[i-1]>=a[i])
			down[i] = down[i-1]+1;
		else
			down[i] = 1;
	}
	for(int i=n-2;i>=0;i--)
	{
		if(a[i]<=a[i+1])
			up[i] = up[i+1]+1;
		else
			up[i] = 1;
	}
	rep(i,0,m)
	{
		int l, r;
		scanf("%d%d",&l,&r);
		if(up[l-1]+down[r-1]>=r-l+1)
			printf("Yes\n");
		else
			printf("No\n");
	}

}