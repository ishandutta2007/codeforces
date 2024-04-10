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
LL a[N];
LL b[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	map<LL, int> m;
	int n, k;
	MEM(b, 0);
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		m[x]++;
		a[i] = x;
	}
		LL ans = 0;
	if (k == 1)
	{
		for (auto &p : m)
		{
			LL o = p.second;
			ans += o*(o - 1)*(o - 2) / 6;
		}
	}
	else
	{
		if (m.count(0))
		{
			LL o = m[0];
			ans += o*(o - 1)*(o - 2) / 6;
		}
		m.clear();
		for (int i = 0; i < n; i++)
		{
			if (a[i] % k == 0)
			{
			if (a[i] == 0) continue;
			if (m.count(a[i] / k)) b[i] = m[a[i] / k];
				
			}
			m[a[i]] ++;
			
		}
		m.clear();
		for (int i = n - 1; i >= 0; i--)
		{
			if (a[i] == 0) continue;
			if (m.count(a[i] * k)) ans += (LL)b[i] * m[a[i] * k];
			m[a[i]]++;
		}
	}
	cout << ans << endl;
	return 0;
}