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
	if(n<=3){ printf("-1\n"); return;}
	if(n==4){ printf("3 1 4 2\n"); return;}
	if(n==5){ printf("1 3 5 2 4\n"); return;}
	
	ans.clear();
	for(int i=2; i<=n; i+=2) ans.push_back(i);
	reverse(ans.begin(),ans.end());
	swap(ans[0], ans[2]);
	swap(ans[1], ans[2]);
	if(n&1) swap(ans[0], ans[2]);
	
	for(int i=1; i<=n; i+=2) printf("%d ",i);
	for(int i=0; i<(int)ans.size(); ++i) printf("%d ",ans[i]);
	putchar('\n');
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}