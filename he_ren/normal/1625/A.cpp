#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

void solve(void)
{
	int n,l;
	scanf("%d%d",&n,&l);
	vector<int> a(n);
	for(int &x: a) scanf("%d",&x);
	
	int ans = 0;
	for(int i=0; i<l; ++i)
	{
		int cnt[2] = {0,0};
		for(int x: a)
			++cnt[(x>>i)&1];
		ans = ans | (cnt[0] > cnt[1]? 0: 1) << i;
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