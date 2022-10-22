#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

void solve(void)
{
	int n,m;
	scanf("%d%d",&n,&m);
	int mxx = 0, mxy = 0;
	for(int i=1; i<=m; ++i)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		mxx = max(mxx, x);
		mxy = max(mxy, y);
	}
	if(mxx + mxy > n)
	{
		printf("IMPOSSIBLE\n");
	}
	else
	{
		mxy += n - mxx - mxy;
		cout << string(mxx, 'R') << string(mxy, 'W') << endl;
	}
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}