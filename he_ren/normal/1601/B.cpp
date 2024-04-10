#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 3e5 + 5;

int a[MAXN], b[MAXN];
int pre[MAXN * 2];

void solve(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	for(int i=1; i<=n; ++i) scanf("%d",&b[i]);
	
	int pos = n;
	
	queue<int> q;
	pre[n] = -1; q.push(n);
	while(q.size())
	{
		int u = q.front(); q.pop();
		if(u > n)
		{
			int v = u-n + b[u-n];
			if(pre[v] == 0) pre[v] = u, q.push(v);
			continue;
		}
		
		int l = u - a[u];
		if(l == 0)
		{
			pre[0] = u;
			break;
		}
		
		for(; pos >= l; --pos)
		{
			int v = pos + n;
			pre[v] = u;
			q.push(v);
		}
	}
	
	if(pre[0] == 0)
	{
		printf("-1");
		return;
	}
	
	vector<int> ans(1,0);
	for(int u=0; u!=-1; u=pre[u])
		if(u > n) ans.push_back(u - n);
	reverse(ans.begin(), ans.end());
	
	printf("%d\n",(int)ans.size());
	for(int x: ans) printf("%d ",x);
}

int main(void)
{
	int T = 1;
	while(T--) solve();
	return 0;
}