#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <queue>
#include <stack>
#include <set>
#include <vector>

using namespace std;

const int MAXN = 100005;

long long n,d,b;
long long a[MAXN];
long long c[MAXN];
long long tol[MAXN],tor[MAXN];
long long sl[MAXN],sr[MAXN];

long long SUM(long long *a,long long l,long long r)
{
	l = max(l,1ll);
	r = min(r,n);
	return a[r] - a[l - 1];
}

bool can(long long mid)
{
	memcpy(a,c,sizeof(a));
	memset(tol,0,sizeof(tol));
	memset(tor,0,sizeof(tor));
	memset(sl,0,sizeof(sl));
	memset(sr,0,sizeof(sr));
	int l = mid + 1,r = n - mid;
	long long suml = ((n + 1) / 2 - mid) * b;
	for (int i = 1;i <= n;i++)
	{
		if (suml)
		{
			if (a[i] > suml)
				tol[i] = suml,a[i] -= suml,suml = 0;
			else
				tol[i] = a[i],suml -= a[i],a[i] = 0;
		}
		if (!suml)
			tor[i] = a[i];
	}
	for (int i = 1;i <= n;i++)
	{
		sl[i] = sl[i - 1] + tol[i];
		sr[i] = sr[i - 1] + tor[i];
	}
	long long minus = 0;
	for (long long i = l;i <= (n + 1) / 2;i++,minus += b)
		if (SUM(sl,1,i + d * i) - minus < b)
			return false;
	minus = 0;
	for (long long i = r;i > (n + 1) / 2;i--,minus += b)
		if (SUM(sr,i - d * (n - i + 1),n) - minus < b)
			return false;
	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> d >> b;
	for (int i = 1;i <= n;i++)
		cin >> c[i];
	long long low = 0,high = (n + 1) / 2;
	while (low < high)
	{
		long long mid = (low + high) >> 1;
		if (can(mid))
			high = mid;
		else
			low = mid + 1;
	}
	cout << low << endl;
	return 0;
}