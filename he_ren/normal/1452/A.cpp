#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

void solve(void)
{
	int x,y;
	scanf("%d%d",&x,&y);
	x = abs(x); y = abs(y);
	if(x > y) swap(x,y);
	
	if(x == y) printf("%d\n",x + y);
	else printf("%d\n",x * 2 + (y - x) * 2 - 1);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}