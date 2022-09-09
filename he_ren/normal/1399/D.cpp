#include<cstdio>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e5 + 5;

char s[MAXN];

void solve(void)
{
	int n;
	scanf("%d%s",&n,s+1);
	
	stack<int> now[2];
	
	int ans = 0;
	vector<int> vec;
	for(int i=1; i<=n; ++i)
	{
		int x = s[i] - '0';
		if(now[x^1].empty())
			now[x^1].push(++ans);
		
		int res = now[x^1].top();
		vec.push_back(res);
		
		now[x^1].pop();
		now[x].push(res);
	}
	printf("%d\n",ans);
	for(int i=0; i<(int)vec.size(); ++i) printf("%d ",vec[i]);
	putchar('\n');
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}