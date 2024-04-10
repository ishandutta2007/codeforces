#include<cstdio>
#include<iostream>
#include<algorithm>
typedef long long ll;
const int MAXN = 1e5 + 5;
const int MAXM = 1e5 + 5;
using namespace std;

int n,m;
int a[MAXN],b[MAXN];

int main(void)
{
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	for(int i=1; i<=m; ++i) scanf("%d",&b[i]);
	
	ll ans=0;
	for(int i=1; i<=n; ++i)
	{
		int x=lower_bound(b+1,b+m+1,a[i])-b;
		
		ll mn=1e18+5;
		if(x<=m) mn = min(mn, (ll)b[x]-a[i]);
		if(x>1) mn = min(mn, (ll)a[i]-b[x-1]);
		
		ans=max(ans,mn);
	}
	
	cout<<ans;
	return 0;
}