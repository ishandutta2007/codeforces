#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

void solve(void)
{
	int n,m;
	scanf("%d%d",&n,&m);
	set<int> t;
	for(int i=1; i<=n; ++i)
	{
		int x;
		scanf("%d",&x);
		t.insert(x);
	}
	int ans = 0;
	for(int i=1; i<=m; ++i)
	{
		int x;
		scanf("%d",&x);
		if(t.find(x) != t.end()) ++ans;
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