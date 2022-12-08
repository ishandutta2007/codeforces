#include <bits/stdc++.h>
using namespace std;
#define rep(a,b,c) for(int a=b;a<c;++a)
#define debug(x) cerr<<(#x)<<": "<<x<<endl
const int sz = 1e6;

int main()
{
	int n;
	scanf("%d",&n);
	int a[sz];
	rep(i,0,n)
		scanf("%d",&a[i]);
	sort(a,a+n);
	bool ok = false;
	rep(i,2,n)
		if(a[i]<a[i-1]+a[i-2])
			ok = true;
	if(ok)
		printf("YES\n");
	else
		printf("NO\n");
}