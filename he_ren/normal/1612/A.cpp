#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

void solve(void)
{
	int x,y;
	scanf("%d%d",&x,&y);
	
	if((x + y) % 2)
	{
		printf("-1 -1\n");
	}
	else if(x <= (x + y) / 2)
	{
		printf("%d %d\n",x,(x + y) / 2 - x);
	}
	else
	{
		printf("%d %d\n",(x + y) / 2, 0);
	}
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}