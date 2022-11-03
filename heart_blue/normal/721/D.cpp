#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
LL n, k, x;
LL a[N];

priority_queue<pair<LL, int>, vector<pair<LL, int>>, greater<pair<LL, int>>> pq;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int zero = 0;
	int neg = 0;
	cin >> n >> k >> x;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++)
	{
		if (a[i] == 0) zero++;
		if (a[i] < 0) neg++;
	}
	if (zero > k)
	{
		for (int i = 0; i < k; i++) a[i] -= x;
		for (int i = 0; i < n; i++) cout << a[i] << ' ';
		return 0;
	}
	if (zero > 0)
	{
		k -= zero;
		for (int i = 0; i < n; i++)
		{
			if (a[i] == 0)
			{
				zero--;
				if (zero > 0) a[i] = x;
				else
				{
					if (neg & 1) a[i] = x;
					else a[i] = -x, neg++;
				}
			}
		}
	}
	if (neg % 2 == 0)
	{
		int key = -1;
		LL minv = INF*INF;
		for (int i = 0; i < n; i++)
		{
			if (abs(a[i]) < minv)
			{
				minv = abs(a[i]);
				key = i;
			}
		}
		LL o = minv / x + 1;
		if (o <= k) neg++;
		if (o >= k) o = k;
		if (a[key] < 0) a[key] += o*x;
		else a[key] -= o*x;
		k -= o;
	}
	if (k > 0)
	{
		for (int i = 0; i < n; i++)
		{
			pq.push({ abs(a[i]),i });
		}
		while (k--)
		{
			LL y;
			int o;
			tie(y, o) = pq.top(); pq.pop();
			if (a[o] < 0) a[o] = a[o] - x;
			else a[o] = a[o] + x;
			pq.push({ abs(a[o]),o });
		}
	}
	for (int i = 0; i < n; i++) cout << a[i] << ' ';
	return 0;
}