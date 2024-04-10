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

int n, z, f[200100];
long long cnt[200200];
pair <int,int> a[200100];
vector <int> divisor[200200];

long long power(long long x, long long y)
{
	if (!y) return 1;
	long long r = power(x, y / 2);
	r = r * r % z;
	if (y % 2) r = r * x % z;
	return r;
}

void init()
{
	for (int i = 2; i <= 200000; i++)
		if (divisor[i].empty())
			for (int j = i; j <= 200000; j += i)
				divisor[j].push_back(i);
}

int main()
{
	init();
	cin >> n;
	for (int i = 1; i <= n; i++) scanf("%d", &a[i].first), a[i].second = i;
	for (int i = 1; i <= n; i++) scanf("%d", &a[i + n].first), a[i + n].second = i;
	cin >> z;
	n *= 2;
	
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; )
	{
		int j = i;
		vector <int> b;
		while (j <= n && a[j].first == a[i].first) b.push_back(a[j++].second);
		i = j;
		
		int total = b.size();
		f[total]++;
		for (int j = 0; j < total; ) 
		{
			int k = j;
			while (k < total && b[k] == b[j]) k++;
			f[k - j]--;
			j = k;
		}
	}
	
	long long ans = 1;
	for (int i = 200000; i > 1; i--)
	{
		f[i] += f[i + 1];
		for (int j = 0; j < int(divisor[i].size()); j++)
		{
			int t = i, x = divisor[i][j], y = 0;
			while (t % x == 0) t /= x, y++;
			cnt[x] += 1LL * y * f[i];
		}
	}
	
	for (int i = 2; i <= 200000; i++)
		if (cnt[i]) ans = ans * power(i, cnt[i]) % z;
	
	cout << ans << endl;
}