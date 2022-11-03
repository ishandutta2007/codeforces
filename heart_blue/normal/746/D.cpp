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
const int N = 4e5 + 10;
int ans[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k, a, b;
	cin >> n >> k >> a >> b;

	char c1 = 'G', c2 = 'B';
	if (a < b) swap(a, b), swap(c1, c2);
	if (b == 0)
	{
		if (n > k) cout << "NO" << endl;
		else cout << string(a, c1) << endl;
		return 0;
	}
	for (int i = 1; i <= a; i++)
	{
		for (int j = i-1; j <= i; j++)
		{
			if (j == 0) continue;
			if ((a + (i - 1)) / i > k) continue;
			if (b < j) continue;
			if ((b + (j - 1)) / j > k) continue;
			int x = a / i;
			int y = b / j;
			int o1 = a%i;
			int o2 = b%j;
			int t1 = i, t2 = j;
			while (1)
			{
				if (t1 <= 0 && t2 <= 0) break;
				if (t1-- > 0)
				{
					cout << string(x, c1);
					if (o1-- > 0) cout << c1;
				}
				if (t2-- > 0)
				{
					cout << string(y, c2);
					if (o2-- > 0) cout << c2;
				}
			}
			return 0;
		}
	}
	cout << "NO" << endl;
	return 0;
}