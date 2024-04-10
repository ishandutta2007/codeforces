#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

void solve(void)
{
	int x,y;
	scanf("%d%d",&x,&y);
	if(x > y)
	{
		printf("%d\n",x+y);
	}
	else
	{
		int t = y - y % x;
		printf("%lld\n",(ll)(t + y) / 2);
	}
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}