#include <bits/stdc++.h>
using namespace std;
#define rep(a,b,c) for(int a=b;a<c;++a)
#define debug(x) cerr<<(#x)<<": "<<x<<endl
const int sz = 2e5;

int main()
{
	int n, m;
	int a[sz], b[sz];

	bool seen[sz];
	rep(i,0,sz)
		seen[i] = false;
	scanf("%d%d",&n,&m);
	rep(i,0,n)
		scanf("%d",&a[i]);
	for(int i=n-1;i>=0;i--)
	{
		if(!seen[a[i]])
			b[i]=1;
		else
			b[i]=0;
		seen[a[i]] = true;
		if(i<n-1)
			b[i]+=b[i+1];
	}
	int l;
	rep(i,0,m)
	{
		scanf("%d",&l);
		printf("%d\n",b[l-1]);
	}
}