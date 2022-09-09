#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;
typedef long long ll;
const int MAXN = 2e5 + 5;

int p[MAXN];
int lst[MAXN], nxt[MAXN];

int pos[MAXN];

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&p[i]);
	
	static stack<int> sta;
	for(int i=1; i<=n; ++i)
	{
		while(!sta.empty() && p[sta.top()] <= p[i]) sta.pop();
		
		if(sta.empty()) lst[i] = 0;
		else lst[i] = sta.top();
		sta.push(i);
	}
	
	while(!sta.empty()) sta.pop();
	for(int i=n; i>=1; --i)
	{
		while(!sta.empty() && p[sta.top()] <= p[i]) sta.pop();
		
		if(sta.empty()) nxt[i] = n+1;
		else nxt[i] = sta.top();
		sta.push(i);
	}
	
	for(int i=1; i<=n; ++i)
		pos[p[i]] = i;
	
	ll ans = 0;
	for(int i=1; i<=n; ++i)
	{
		int l=lst[i], r=nxt[i];
		if(r-i <= i-l)
		{
			for(int j=i+1; j<r; ++j)
			{
				int x = pos[p[i] - p[j]];
				if(x>l && x<i) ++ans;
			}
		}
		else
		{
			for(int j=l+1; j<i; ++j)
			{
				int x = pos[p[i] - p[j]];
				if(x>i && x<r) ++ans;
			}
		}
	}
	printf("%lld",ans);
	return 0;
}