#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

void solve(void)
{
	int n,m,x,y,tx,ty;
	scanf("%d%d%d%d%d%d",&n,&m,&x,&y,&tx,&ty);
	int dx = 1, dy = 1;
	
	int ans = 0;
	while(1)
	{
		if(x == tx || y == ty) break;
		if(x + dx > n || x + dx < 1) dx = -dx;
		if(y + dy > m || y + dy < 1) dy = -dy;
		x += dx; y += dy;
		++ans;
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