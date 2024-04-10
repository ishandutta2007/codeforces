#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e5 + 5;

ll a[MAXN];

int main(void)
{
	int n;
	ll d,x;
	scanf("%d%lld%lld",&n,&d,&x);
	for(int i=1; i<=n; ++i) scanf("%lld",&a[i]);
	
	sort(a+1,a+n+1);
	
	vector<ll> vec;
	for(int i=2; i<=n; ++i)
	{
		if(a[i] - a[i-1] <= x){ vec.push_back(0); continue;}
		vec.push_back((a[i] - a[i-1] + x - 1) / x - 1);
	}
	sort(vec.begin(), vec.end());
	
	int ans = n;
	for(int i=0; i<(int)vec.size() && vec[i] <= d; ++i)
		--ans, d -= vec[i];
	printf("%d",ans);
	return 0;
}