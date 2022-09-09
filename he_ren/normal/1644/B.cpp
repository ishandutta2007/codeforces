#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

void solve(void)
{
	int n;
	scanf("%d",&n);
	
	if(n == 3)
	{
		printf(
			"3 2 1\n"
			"1 3 2\n"
			"3 1 2\n");
		return;
	}
	for(int i=1; i<=n; ++i)
	{
		for(int j=0; j<n; ++j)
			printf("%d ",i-j >= 1? i-j: i-j+n);
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