#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

void solve(void)
{
	int n;
	scanf("%d",&n);
	int sum = 0;
	for(int i=1; i<=n; ++i)
	{
		int x;
		scanf("%d",&x);
		sum += x - 1;
	}
	if(sum & 1) printf("errorgorn\n");
	else printf("maomao90\n");
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}