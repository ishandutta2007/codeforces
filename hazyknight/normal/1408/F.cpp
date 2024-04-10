#include <bits/stdc++.h>

using namespace std;

const int MAXN = 15005;

int n;

vector<pair<int,int> > ans;

void solve(int l,int r)
{
	if (l == r)
		return;
	int mid = l + r >> 1;
	solve(l,mid);
	solve(mid + 1,r);
	for (int i = l;i <= mid;i++)
		ans.push_back(make_pair(i,mid + 1 + i - l));
}

int main()
{
	scanf("%d",&n);
	int N = 1;
	while (N * 2 < n)
		N <<= 1;
	solve(1,N);
	solve(n - N + 1,n);
	printf("%d\n",(int)ans.size());
	for (int i = 0;i < ans.size();i++)
		printf("%d %d\n",ans[i].first,ans[i].second);
	return 0;
}