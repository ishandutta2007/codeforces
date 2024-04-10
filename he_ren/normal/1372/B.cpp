#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

void solve(void)
{
	int n;
	scanf("%d",&n);
	
	for(int i=2; i*i<=n; ++i) if(n%i == 0)
	{
		printf("%d %d\n",n/i,n - n/i);
		return;
	}
	printf("1 %d\n",n-1);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}