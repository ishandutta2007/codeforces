#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e5 + 5;

int a[MAXN];

void solve(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	static int sum[MAXN], num[MAXN];
	for(int i=0; i<=n; ++i) sum[i] = num[i] = 0;
	
	sort(a+1,a+n+1);
	vector<int> vec;
	for(int i=1,j=1; i<=n; i=j)
	{
		while(j<=n && a[j] == a[i]) ++j;
		sum[j-i] += j-i;
		++num[j-i];
	}
	
	for(int i=1; i<=n; ++i)
		sum[i] += sum[i-1], num[i] += num[i-1];
	
	int ans = n;
	for(int i=1; i<=n; ++i)
		ans = min(ans, sum[i-1] + (sum[n] - sum[i]) - i * (num[n] - num[i]));
	printf("%d\n",ans);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}