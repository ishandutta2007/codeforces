#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e3 + 5;

int a[MAXN], b[MAXN];

void solve(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d%d",&a[i],&b[i]);
	if(n&1){ printf("1\n"); return;}
	
	sort(a+1,a+n+1);
	sort(b+1,b+n+1);
	
	int mid = n / 2;
	printf("%lld\n",(ll)(a[mid+1] - a[mid] + 1) * (b[mid+1] - b[mid] + 1));
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}