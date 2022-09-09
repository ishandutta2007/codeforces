#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<queue>
#include<deque>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<pii,int> piii;
const int MAXN = 2e5 + 5;

char s[MAXN];

void solve(void)
{
	int n;
	scanf("%d%s",&n,s+1);
	
//	static bool del[MAXN];
//	for(int i=1; i<=n; ++i) del[i] = 0;
	
	deque<int> q;
	for(int i=2; i<=n; ++i)
		if(s[i] == s[i-1])
			q.push_back(i);
	
	int ans = 0;
	for(int i=1,j=1; i<=n; i=j)
	{
		while(j<=n && s[i]==s[j]) ++j;
		while(!q.empty() && q.front() < i) q.pop_front();
		
		if(!q.empty() && q.front() <= n)
		{
			q.pop_front(); ++ans;
			continue;
		}
		
		if(j>n) ++ans;
		else q.push_front(j);
	}
	
	printf("%d\n",ans);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}