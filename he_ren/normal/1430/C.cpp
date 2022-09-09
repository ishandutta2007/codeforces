#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

void solve(void)
{
	int n;
	scanf("%d",&n);
	
	vector<pii> ans;
	
	int lst = n;
	for(int i=n-1; i>=1; --i)
	{
		ans.push_back(make_pair(i,lst));
		lst = (lst + i + 1)/2;
	}
	
	printf("%d\n",lst);
	for(int i=0; i<n-1; ++i)
		printf("%d %d\n",ans[i].first,ans[i].second);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}