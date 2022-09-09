#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

void solve(void)
{
	int n;
	scanf("%d",&n);
	map<int,int> t;
	for(int i=1; i<=n; ++i)
	{
		int x;
		scanf("%d",&x);
		t[abs(x)]++;
	}
	
	int ans = 0;
	for(auto it: t)
	{
		if(it.first == 0 || it.second == 1) ++ans;
		else ans += 2;
	}
	
	cout << ans << endl;
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}