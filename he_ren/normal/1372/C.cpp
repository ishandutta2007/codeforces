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
	
	int ans = 0;
	for(int i=1; i<=n; ++i)
		if(a[i] != i && a[i-1] == i-1)
			++ans;
	printf("%d\n",min(ans, 2));
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}