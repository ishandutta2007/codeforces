#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

void solve(void)
{
	int n,l,r,d;
	scanf("%d%d%d%d",&n,&l,&r,&d);
	vector<int> a;
	for(int i=1; i<=n; ++i)
	{
		int x;
		scanf("%d",&x);
		if(l <= x && x <= r)
			a.push_back(x);
	}
	sort(a.begin(), a.end());
	
	int ans = 0;
	for(int x: a)
		if(x <= d) ++ans, d-=x;
	printf("%d\n",ans);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}