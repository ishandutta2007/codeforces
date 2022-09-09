#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e5 + 5;

int a[MAXN];

void solve(void)
{
	int n,x;
	scanf("%d%d",&n,&x);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	int l = n - x + 1, r = x;
	static int b[MAXN];
	memcpy(b, a, (n+1)<<2);
	sort(b+1,b+n+1);
	
	for(int i=l; i<=r; ++i) if(a[i] != b[i])
	{
		printf("NO\n");
		return;
	}
	printf("YES\n");
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}