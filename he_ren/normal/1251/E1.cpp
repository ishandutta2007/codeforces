#include<cstdio>
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
typedef unsigned int uint;
const int MAXN = 2e5 + 5;

vector<int> a[MAXN];
int sum[MAXN];
priority_queue<int,vector<int>,greater<int> > q;

void solve(void)
{
	int n;
	scanf("%d",&n);
	for(int i=0; i<n; ++i) a[i].clear();
	for(int i=1; i<=n; ++i)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		a[x].push_back(y);
	}
	
	sum[0]=0;
	for(int i=1; i<=n; ++i)
		sum[i] = sum[i-1]+a[i-1].size();
	
	while(!q.empty()) q.pop();
	ll ans=0;
	for(int i=n-1; i>=0; --i)
	{
		for(uint j=0; j<a[i].size(); ++j) q.push(a[i][j]);
		
		while(n-(int)q.size() < i)
			ans += q.top(), q.pop();
	}
	cout<<ans<<endl;
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}