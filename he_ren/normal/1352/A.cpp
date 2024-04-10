#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;

vector<int> ans;

void solve(void)
{
	int n;
	scanf("%d",&n);
	
	ans.clear();
	int mod = 1;
	for(int i=1; i<=5; ++i)
	{
		mod *= 10;
		if(n%mod) ans.push_back(n%mod);
		n -= n%mod;
	}
	
	printf("%d\n",(int)ans.size());
	for(int i=0; i<(int)ans.size(); ++i)
		printf("%d ",ans[i]);
	putchar('\n');
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}