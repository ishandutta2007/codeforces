#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e2 + 5;

char s[MAXN][MAXN];

void solve(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%s",s[i]+1);
	
	vector<pii> ans;
	if(s[1][2] == s[2][1])
	{
		if(s[n][n-1] == s[1][2]) ans.push_back(make_pair(n,n-1));
		if(s[n-1][n] == s[1][2]) ans.push_back(make_pair(n-1,n));
	}
	else if(s[n-1][n] == s[n][n-1])
	{
		if(s[n][n-1] == s[1][2]) ans.push_back(make_pair(1,2));
		if(s[n][n-1] == s[2][1]) ans.push_back(make_pair(2,1));
	}
	else
	{
		ans.push_back(make_pair(2,1));
		if(s[n][n-1] == s[1][2]) ans.push_back(make_pair(n,n-1));
		if(s[n-1][n] == s[1][2]) ans.push_back(make_pair(n-1,n));
	}
	
	printf("%d\n",(int)ans.size());
	for(int i=0; i<(int)ans.size(); ++i)
		printf("%d %d\n",ans[i].first,ans[i].second);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}