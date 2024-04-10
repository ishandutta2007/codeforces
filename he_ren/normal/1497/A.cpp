#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e2 + 5;

int a[MAXN];

void solve(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	a[0] = -1;
	sort(a+1,a+n+1);
	for(int i=1; i<=n; ++i) if(a[i] != a[i-1]) printf("%d ",a[i]);
	for(int i=1; i<=n; ++i) if(a[i] == a[i-1]) printf("%d ",a[i]);
	printf("\n");
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}