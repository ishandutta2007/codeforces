#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 100005;

int T,n;
int sum[MAXN];

char s[MAXN];
char t[MAXN];
char tmp[MAXN];

set<int> S[26];

void modify(int p,int v)
{
	while (p <= n)
	{
		sum[p] += v;
		p += p & -p;
	}
}

int query(int p)
{
	int res = 0;
	while (p >= 1)
	{
		res += sum[p];
		p -= p & -p;
	}
	return res;
}

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%s%s",&n,s + 1,t + 1);
		for (int i = 0;i < 26;i++)
			S[i].clear();
		for (int i = 1;i <= n;i++)
			S[s[i] - 'a'].insert(i);
		for (int i = 1;i <= n;i++)
			sum[i] = 0;
		ll add = 0;
		int st = 1;
		for (int i = 1,j = 1;i <= n;i++,j++)
		{
			if (query(i) != query(i - 1))
			{
				j--;
				continue;
			}
			char c = t[j] - 'a';
			bool ok = 0;
			for (int j = 0;j < c;j++)
				if (S[j].size())
					ok = 1;
			if (ok)
				break;
			if (!S[c].size())
				break;
			int p = *S[c].begin();
			S[c].erase(p);
			add += p - i - query(p - 1) + query(i - 1);
			modify(p,1);
			i--;
		}
		st = n + 1;
		for (int i = n;i >= 1;i--)
			if (query(i) == query(i - 1))
				s[--st] = s[i];
		for (int i = 0;i < 26;i++)
			S[i].clear();
		for (int i = st;i <= n;i++)
			S[s[i] - 'a'].insert(i);
		int tot = 0,ans = 1e9;
		for (int i = st;i <= n;i++)
		{
			char c = t[i] - 'a';
			int MIN = 1e9;
			for (int j = 0;j < c;j++)
				if (S[j].size())
					MIN = min(MIN,*S[j].begin());
			if (MIN < 1e9)
				ans = min(ans,MIN - i + tot);
			if (!S[c].size())
				break;
			int p = *S[c].begin();
			for (int j = i;j <= p;j++)
				S[s[j] - 'a'].erase(j);
			for (int j = p;j > i;j--)
				s[j] = s[j - 1];
			s[i] = c + 'a';
			for (int j = i + 1;j <= p;j++)
				S[s[j] - 'a'].insert(j);
			tot += p - i;
			if (tot > n)
				break;
		}
		printf("%lld\n",ans == 1e9 ? -1 : ans + add);
	}
	return 0;
}