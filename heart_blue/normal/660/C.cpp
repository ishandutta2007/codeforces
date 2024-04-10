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
const int N = 1e5 + 10;
int gcd(int n, int m)
{
	return m == 0 ? n : gcd(m, n%m);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	vector<int> v;
	int n, k;
	cin >> n >> k;
	v.resize(n);
	int l, r;
	l = 0;
	r = 0;
	int ansl = 0, ansr = -1;
	int ans = 0;
	for (int i = 0; i < n; i++) cin >> v[i];
	while (l < n && r < n)
	{
		if (v[r] == 0)
		{
			if (k == 0)
			{
				k += 1 - v[l];
				l++;
			}
			else
			{
				if (r - l + 1 > ans)
				{
					ans = r - l + 1;
					ansl = l;
					ansr = r;
				}
				k--;
				r++;
			}
		}
		else
		{
			
			if (r - l + 1 > ans)
			{
				ans = r - l + 1;
				ansl = l;
				ansr = r;
			}
			r++;
		}
	}
	cout << ans << endl;
	for (int i = ansl; i <= ansr; i++) v[i] = 1;
	for (auto &x : v) cout << x << ' ';
	return 0;
}