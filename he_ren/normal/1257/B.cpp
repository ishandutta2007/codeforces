#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

void solve(void)
{
	int x,y;
	scanf("%d%d",&x,&y);
	
	int T = 5e3;
	for(int i=1; i<=T && y>x; ++i)
	{
		if(y%3 == 0) y = y/3 * 2;
		else y = (y - y%3 + 3)/3 * 2;
	}
	
	if(y <= x) printf("YES\n");
	else printf("NO\n");
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}