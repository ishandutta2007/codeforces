#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e5 + 5;

int p[MAXN];

void solve(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&p[i]);
	
	vector<pii> pos;
	static bool del[MAXN], iskey[MAXN];
	for(int i=1; i<=n; ++i) del[i] = iskey[i] = 0;
	for(int i=1,j=1; i<=n; i=j)
	{
		while(j<=n && p[i] == p[j]) ++j;
		pos.push_back(make_pair(i, j));
		del[i] = 1; iskey[p[i]] = 1;
	}
	del[n+1] = 1;
	
	queue<int> q;
	for(int i=1; i<=n; ++i) if(!iskey[i]) q.push(i);
	for(int i=1; i<=n; ++i)
	{
		if(del[i]) printf("%d ",p[i]);
		else printf("%d ",q.front()), q.pop();
	}
	printf("\n");
	
	static int ans[MAXN];
	for(int i=1; i<=n; ++i)
		if(del[i]) ans[i] = p[i];
	
	set<pii> t;
	for(int i=1; i<=n; ++i)
		if(del[i] && !del[i+1])
			t.insert(make_pair(p[i], i+1));
	for(int i=n; i>=1; --i)
		if(!iskey[i])
		{
			pii cur = *t.lower_bound(make_pair(i,0)); t.erase(cur);
			ans[cur.second] = i;
			++cur.second;
			if(!del[cur.second])
				t.insert(cur);
		}
	
	for(int i=1; i<=n; ++i)
		printf("%d ",ans[i]);
	printf("\n");
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}