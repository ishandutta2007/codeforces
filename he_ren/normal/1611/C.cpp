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
	
	if(a[1] != n && a[n] != n)
	{
		printf("-1\n");
		return;
	}
	else
	{
		if(a[1] == n) reverse(a+2, a+n+1);
		else reverse(a+1,a+n);
		for(int i=1; i<=n; ++i) printf("%d ",a[i]);
		printf("\n");
	}
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}