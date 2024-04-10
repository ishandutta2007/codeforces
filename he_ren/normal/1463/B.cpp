#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 50 + 5;

int a[MAXN];

void solve(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	ll sum[2] = {0,0};
	for(int i=1; i<=n; ++i)
		sum[i&1] += a[i];
	
	int k = (sum[0] >= sum[1]);
	for(int i=1; i<=n; ++i)
		printf("%d ",(i&1) == k? 1: a[i]);
	putchar('\n');
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}