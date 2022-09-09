#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e5 + 5;

vector<pii> read(int n)
{
	static int a[MAXN];
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	vector<pii> res;
	for(int i=1,j=1; i<=n; i=j)
	{
		while(j<=n && a[i] == a[j]) ++j;
		res.emplace_back(a[i], j-i);
	}
	return res;
}

void solve(void)
{
	int n;
	scanf("%d",&n);
	auto a = read(n), b = read(n);
	
	static int need[MAXN];
	memset(need, 0, (n+1)<<2);
	
	for(int i=(int)a.size()-1, j=(int)b.size()-1; j>=0; --j)
	{
		while(1)
		{
			int t = min(a[i].second, need[a[i].first]);
			a[i].second -= t; need[a[i].first] -= t;
			if(a[i].first == b[j].first) break;
			else if(a[i].second)
			{
				printf("NO\n");
				return;
			}
			--i;
		}
		if(a[i].second > b[j].second)
		{
			printf("NO\n");
			return;
		}
		need[a[i].first] += b[j].second - a[i].second;
		--i;
	}
	printf("YES\n");
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}