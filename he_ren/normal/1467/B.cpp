#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 3e5 + 5;

int n;
int a[MAXN], f[MAXN];
bool chk(int x){ return x > 1 && x < n && ((a[x] > a[x-1] && a[x] > a[x+1]) || (a[x] < a[x-1] && a[x] < a[x+1]));}

void solve(void)
{
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	f[n] = 0;
	int sum = 0;
	for(int i=2; i<n; ++i)
		sum += (f[i] = chk(i));
	
	int ans = sum;
	for(int i=2; i<n; ++i)
	{
		int t = a[i];
		a[i] = a[i-1];
		ans = min(ans, sum - f[i] - f[i-1] - f[i+1] + chk(i) + chk(i-1) + chk(i+1));
		a[i] = a[i+1];
		ans = min(ans, sum - f[i] - f[i-1] - f[i+1] + chk(i) + chk(i-1) + chk(i+1));
		a[i] = t;
	}
	printf("%d\n",ans);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}