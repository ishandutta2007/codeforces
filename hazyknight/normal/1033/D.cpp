#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <map>

using namespace std;

const long long MOD = 998244353;

int n,m;

long long a,ans;
long long b[505];

map<int,int> cnt;

long long gcd(long long a,long long b)
{
	return b ? gcd(b,a % b) : a;
}

long long SQRT(long long v)
{
	long long low = 1,high = 2000000000;
	while (low < high)
	{
		long long mid = (low + high + 1) >> 1;
		if (mid * mid <= v)
			low = mid;
		else
			high = mid - 1;
	}
	return low;
}

long long HSQRT(long long v)
{
	long long low = 1,high = 2000000;
	while (low < high)
	{
		long long mid = (low + high + 1) >> 1;
		if (mid * mid * mid <= v)
			low = mid;
		else
			high = mid - 1;
	}
	return low;
}

int main()
{
	ios::sync_with_stdio(false);
	ans = 1;
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		cin >> a;
		long long tot = SQRT(a);
		if (tot * tot == a)
		{
			long long tot2 = SQRT(tot);
			if (tot2 * tot2 == tot)
				cnt[tot2] += 4;
			else
				cnt[tot] += 2;
			continue;
		}
		tot = HSQRT(a);
		if (tot * tot * tot == a)
			cnt[tot] += 3;
		else
			b[++m] = a;
	}
	for (int i = 1;i <= m;i++)
	{
		if (b[i] == 1)
			continue;
		long long p = 0;
		for (map<int,int>::const_iterator j = cnt.begin();j != cnt.end();j++)
			if (b[i] % (*j).first == 0)
			{
				p = (*j).first;
				break;
			}
		if (p)
		{
			cnt[p]++;
			cnt[b[i] / p]++;
			continue;
		}
		long long p1 = 0,p2 = 0,cnt1 = 1,cnt2 = 1;
		for (int j = i + 1;j <= m;j++)
		{
			long long tot = gcd(b[i],b[j]);
			if (tot == b[i])
			{
				cnt1++;
				cnt2++;
			}
			else if (tot > 1)
			{
				if (!p1)
				{
					p1 = tot;
					p2 = b[i] / tot;
				}
			}
		}
		if (!p1)
		{
			(ans *= cnt1 + 1) %= MOD;
			(ans *= cnt2 + 1) %= MOD;
			for (int j = i + 1;j <= m;j++)
				if (gcd(b[i],b[j]) == b[i])
					b[j] = 1;
		}
		else
		{
			cnt[p1]++;
			cnt[p2]++;
		}
	}
	for (map<int,int>::const_iterator i = cnt.begin();i != cnt.end();i++)
		(ans *= (*i).second + 1) %= MOD;
	cout << ans << endl;
	return 0;
}