#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

void solve(void)
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	int x,y,z;
	scanf("%d%d%d",&x,&y,&z);
	
	int ans = min(c,y);
	c -= ans; y -= ans;
	ans *= 2;
	
	int tmp = min(c,z);
	c -= tmp; z -= tmp;
	
	tmp = min(a,z);
	a -= tmp; z -= tmp;
	
	tmp = min(b,z);
	b -= tmp; z -= tmp;
	ans -= tmp * 2;
	
	printf("%d\n",ans);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}