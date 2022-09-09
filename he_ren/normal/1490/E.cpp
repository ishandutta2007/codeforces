#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e5 + 5;

int a[MAXN];
ll sum[MAXN];

void solve(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	static pii p[MAXN];
	for(int i=1; i<=n; ++i) p[i] = make_pair(a[i], i);
	
	sort(p+1,p+n+1);
	for(int i=1; i<=n; ++i) sum[i] = sum[i-1] + p[i].first;
	
	for(int i=n-1; i>=0; --i)
		if(sum[i] < p[i+1].first)
		{
			vector<int> ans;
			for(int j=i+1; j<=n; ++j) ans.push_back(p[j].second);
			sort(ans.begin(),ans.end());
			
			printf("%d\n",(int)ans.size());
			for(int j=0; j<(int)ans.size(); ++j) printf("%d ",ans[j]);
			putchar('\n');
			return;
		}
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}