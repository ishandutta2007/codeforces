#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e3 + 5;

int n;
int a[MAXN];

vector<pii> ans;
bool chk(int x)
{
	multiset<int> t;
	for(int i=1; i<=n; ++i) t.insert(a[i]);
	
	ans.clear();
	while(t.size())
	{
		int p = *t.rbegin(); t.erase(t.find(p));
		if(t.find(x - p) == t.end()) return 0;
		t.erase(t.find(x - p));
		ans.push_back(make_pair(p, x - p));
		x = p;
	}
	return t.empty();
}

void solve(void)
{
	scanf("%d",&n);
	n *= 2;
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	sort(a+1,a+n+1);
	for(int i=1; i<n; ++i)
		if(chk(a[i] + a[n]))
		{
			printf("YES\n%d\n",a[i] + a[n]);
			for(int j = 0; j < (int)ans.size(); ++j)
				printf("%d %d\n",ans[j].first,ans[j].second);
			return;
		}
	printf("NO\n");
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}