#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

void solve(void)
{
	int n,d;
	scanf("%d%d",&n,&d);
	int flag = 0;
	for(int i=1; i<=n; ++i)
	{
		int x;
		scanf("%d",&x);
		flag |= x;
	}
	
	printf(flag? "YES\n": "NO\n");
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}