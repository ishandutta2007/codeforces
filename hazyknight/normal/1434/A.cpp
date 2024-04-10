#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100005;

int n,ans,MAX;
int cur[MAXN];
int a[6];
int b[MAXN];

vector<pair<int,int> > S;

int main()
{
	for (int i = 1;i <= 6;i++)
		scanf("%d",&a[i]);
	sort(a + 1,a + 7);
	scanf("%d",&n);
	for (int i = 1;i <= n;i++)
	{
		scanf("%d",&b[i]);
		cur[i] = 6;
		for (int j = 6;j >= 1;j--)
			S.push_back(make_pair(b[i] - a[j],i));
		MAX = max(MAX,b[i] - a[6]);
	}
	sort(S.begin(),S.end());
	ans = 2e9;
	for (int i = 0;i < S.size();i++)
	{
		ans = min(ans,MAX - S[i].first);
		int u = S[i].second;
		if (cur[u] == 1)
			break;
		MAX = max(MAX,b[u] - a[--cur[u]]);
	}
	printf("%d\n",ans);
	return 0;
}