#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 300005;

int n,ans2;

pair<int,int> a[MAXN];
pair<int,int> b[MAXN];

ll ans1;
ll v[MAXN][2];

void solve(int l,int r,int w)
{
	if (l > r || w < 0)
		return;
	int p1 = l,p2 = r;
	for (int i = l;i <= r;i++)
		if (a[i].first >> w & 1)
			b[p2--] = a[i];
		else
			b[p1++] = a[i];
	reverse(b + p2 + 1,b + r + 1);
	for (int i = l;i <= r;i++)
		a[i] = b[i];
	int mid = p1 - 1;
	solve(l,mid,w - 1);
	solve(mid + 1,r,w - 1);
	int p = l;
	p1 = l,p2 = mid + 1;
	while (p1 <= mid && p2 <= r)
	{
		if (a[p1].second < a[p2].second)
		{
			v[w][0] += p2 - mid - 1;
			b[p++] = a[p1++];
		}
		else
		{
			v[w][1] += p1 - l;
			b[p++] = a[p2++];
		}
	}
	while (p1 <= mid)
	{
		v[w][0] += p2 - mid - 1;
		b[p++] = a[p1++];
	}
	while (p2 <= r)
	{
		v[w][1] += p1 - l;
		b[p++] = a[p2++];
	}
	for (int i = l;i <= r;i++)
		a[i] = b[i];
}

int main()
{
	scanf("%d",&n);
	for (int i = 1;i <= n;i++)
	{
		scanf("%d",&a[i].first);
		a[i].second = i;
	}
	solve(1,n,29);
	for (int i = 29;i >= 0;i--)
	{
		ans1 += min(v[i][0],v[i][1]);
		if (v[i][0] > v[i][1])
			ans2 ^= (1 << i);
	}
	printf("%lld %d\n",ans1,ans2);
	return 0;
}