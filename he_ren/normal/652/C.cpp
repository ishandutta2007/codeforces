#include<cstdio>
#include<iostream>
#include<vector>
typedef long long ll;
const int MAXN = 3e5 + 5;
using namespace std;

int p[MAXN];
vector<int> a[MAXN];
int cnt[MAXN];

int main(void)
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; ++i) scanf("%d",&p[i]);
	for(int i=1; i<=m; ++i)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		a[x].push_back(y); a[y].push_back(x);
	}
	
	ll ans=0;
	for(int l=1,r=1; l<=n;)
	{
		while(!cnt[p[r]] && r<=n)
		{
			for(int i=0; i<(int)a[p[r]].size(); ++i) ++cnt[a[p[r]][i]];
			++r;
		}
		ans+=(ll)r-l;
		for(int i=0; i<(int)a[p[l]].size(); ++i) --cnt[a[p[l]][i]];
		++l;
	}
	cout<<ans;
	return 0;
}