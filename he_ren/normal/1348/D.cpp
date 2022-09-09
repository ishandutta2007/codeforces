#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;

inline int calc(int x)
{
	int res=1;
	while(res<=x) res<<=1;
	return res>>1;
}

vector<int> ans;

void solve(void)
{
	int n;
	scanf("%d",&n);
	
	ans.clear();
	int mx = calc(n);
	for(int i=1; i<mx; i<<=1) ans.push_back(i);
	ans.push_back(n - (mx-1));
	
	sort(ans.begin(),ans.end());
	
	printf("%d\n",(int)ans.size()-1);
	for(int i=1; i<(int)ans.size(); ++i) printf("%d ",ans[i]-ans[i-1]);
	putchar('\n');
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}