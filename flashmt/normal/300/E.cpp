#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <utility>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <sstream>
using namespace std;

int d[10100100], p[1000100], P, flag[10100100];
long long cnt[1000100];

int possible(long long n)
{
	for (int i = 0; i < P; i++)
		if (cnt[i])
		{
			long long t = n, u = 0;
			while (t) t /= p[i], u += t;
			if (u < cnt[i]) return 0;
		}
	return 1;
}

int main()
{
	int n, x;
	cin >> n;
	while (n--) scanf("%d", &x), d[x]++;
	for (int i = 10000000; i; i--) d[i] += d[i + 1];
	
	for (int i = 2; i * i <= 10000000; i++)
		if (!flag[i])
			for (int j = i * i; j <= 10000000; j += i)
				flag[j] = -i;
				
	for (int i = 2; i <= 10000000; i++)	
		if (!flag[i]) p[P] = i, flag[i] = P++;
		
	for (int i = 2; i <= 10000000; i++)
	{
		int t = i;
		while (1)
			if (flag[t] >= 0) 
			{
				cnt[flag[t]] += d[i];
				break;
			}
			else cnt[flag[-flag[t]]] += d[i], t /= -flag[t];
	}
	
	long long low = 1, high = 1LL << 50, ans = 0;
	while (low <= high)
	{
		long long mid = (low + high) / 2;
		if (possible(mid)) ans = mid, high = mid - 1;
		else low = mid + 1;
	}
	
	cout << ans << endl;
}