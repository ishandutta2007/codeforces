#include<cstdio>
#include<iostream>
#include<algorithm>
typedef long long ll;
const int MAXN = 2e5 + 5;
using namespace std;

ll a[MAXN];

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) cin>>a[i];
	
	sort(a+1,a+n+1);
	ll ans = 1e18+5;
	int cnt=0;
	for(int i=2; i<=n; ++i)
	{
		if(a[i]-a[i-1]<ans) ans=a[i]-a[i-1], cnt=1;
		else if(a[i]-a[i-1]==ans) ++cnt;
	}
	
	cout<<ans<<" "<<cnt;
	return 0;
}