#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int S = 800;
const int MAXN = 200005;
const int MAXM = 310000;

int n;
int a[MAXN];
int cnt[S + 5];
int cnt1[S + 5][S + 5];
int cnt2[MAXM + 5];

ll ans;
ll mark1[MAXM + 5];

void update(int &res,int l,int r,int v,bool flag = 0)
{
	mark1[r] += v;
	if (flag)
		mark1[l - 1] -= v;
	res += cnt2[r] - (flag ? cnt2[l - 1] : 0);
}

int query(int l,int r,int v)
{
	int res = 0;
	int L = l / S * S;
	if (L < l)
		L += S;
	if (L > r)
	{
		update(res,l,r,v,1);
		return res;
	}
	update(res,l,L - 1,v,1);
	while (L + S <= r)
	{
		update(res,L,L + S - 1,v);
		L += S;
	}
	update(res,L,r,v);
	return res;
}

int main()
{
	scanf("%d",&n);
	for (int i = 1;i <= n;i++)
		scanf("%d",&a[i]);
	ll TOT = 0,BIG = 0;
	for (int i = 1;i <= n;i++)
	{
		ans -= mark1[a[i]];
		for (int j = a[i] + 1;j % S != 0;j++)
			ans -= mark1[j];
		ans += (ll)BIG * a[i];
		if (a[i] <= S)
		{
			for (int j = 0;j < a[i];j++)
				ans += (ll)j * cnt1[a[i]][j];
		}
		else
		{
			BIG++;
			ans += TOT;
			for (int j = 0;j * a[i] <= MAXM;j++)
				ans -= (ll)query(max(1,j * a[i]),min(MAXM,j * a[i] + a[i] - 1),j * a[i]) * j * a[i];
		}
		for (int j = 1;j <= S;j++)
			ans += (ll)(a[i] % j) * cnt[j];
		if (a[i] <= S)
			cnt[a[i]]++;
		for (int j = 1;j <= S;j++)
			cnt1[j][a[i] % j]++;
		cnt2[a[i]]++;
		for (int j = a[i] + 1;j % S != 0;j++)
			cnt2[j]++;
		TOT += a[i];
		printf("%lld ",ans);
	}
	printf("\n");
	return 0;
}