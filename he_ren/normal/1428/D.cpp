#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e5 + 5;

int a[MAXN];

void solve(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	vector<pii> ans;
	vector<int> one;
	int two = -1;
	
	int cur = n+1;
	for(int i=n; i>=1; --i)
	{
		if(!a[i]) continue;
		if(a[i] == 1)
		{
			one.push_back(i);
			continue;
		}
		
		if(a[i] == 2)
		{
			if(!one.size()){ printf("-1\n"); return;}
			
			--cur;
			ans.push_back(make_pair(cur, one.back()));
			ans.push_back(make_pair(cur, i));
			one.pop_back(); two = i;
			
			continue;
		}
		
		if(two != -1)
		{
			--cur;
			ans.push_back(make_pair(cur, two));
			ans.push_back(make_pair(cur, i));
		}
		else
		{
			if(!one.size()){ printf("-1\n"); return;}
			
			ans.push_back(make_pair(--cur, one.back()));
			
			--cur;
			ans.push_back(make_pair(cur, one.back()));
			ans.push_back(make_pair(cur, i));
			one.pop_back(); two = i;
		}
		
		two = i;
	}
	
	for(int i=0; i<(int)one.size(); ++i)
		ans.push_back(make_pair(--cur, one[i]));
	
	printf("%d\n",(int)ans.size());
	for(int i=0; i<(int)ans.size(); ++i)
		printf("%d %d\n",ans[i].first,ans[i].second);
}

int main(void)
{
	int T = 1;
	while(T--) solve();
	return 0;
}