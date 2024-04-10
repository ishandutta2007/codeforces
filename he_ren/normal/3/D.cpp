#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 5e4 + 5;

char s[MAXN];
priority_queue<pii> q;

int main(void)
{
	scanf("%s",s+1);
	int n = strlen(s+1);
	
	ll ans = 0;
	int cnt = 0;
	for(int i=1; i<=n; ++i)
	{
		if(s[i] == '(') ++cnt;
		else --cnt;
		
		if(s[i] == '?')
		{
			int a,b;
			scanf("%d%d",&a,&b);
			ans += b;
			q.push(make_pair(-(a-b), i));
			s[i] = ')';
		}
		
		if(cnt < 0)
		{
			if(q.empty()) return printf("-1"), 0;
			pii res = q.top(); q.pop();
			ans += -res.first; s[res.second] = '(';
			cnt += 2;
		}
	}
	
	if(cnt) printf("-1");
	else printf("%lld\n%s",ans,s+1);
	return 0;
}