#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e3 + 5;

int a[MAXN];

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	static pii p[MAXN];
	for(int i=1; i<=n; ++i) p[i] = make_pair(a[i], i);
	sort(p+1,p+n+1);
	
	vector<pii> ans;
	static bool vis[MAXN];
	for(int i=1,j=1; i<=n; i=j)
	{
		while(j<=n && p[i].first == p[j].first) ++j;
		
		for(int k=i; k<j; ++k)
		{
			for(int x=n; x>p[k].second; --x)
				if(vis[x]) ans.push_back(make_pair(p[k].second, x));
			vis[p[k].second] = 1;
		}
	}
	
	printf("%d\n",(int)ans.size());
	for(int i=0; i<(int)ans.size(); ++i)
		printf("%d %d\n",ans[i].first,ans[i].second);
	return 0;
}