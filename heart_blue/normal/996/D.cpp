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
#include <cassert>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e5 + 10;
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= 2 * n; i++) cin >> a[i];
	int ans = 0;
	for (int i = 1; i <= 2 * n; i += 2)
	{
		for (int j = i + 1; j <= 2 * n; j++)
		{
			if (a[j] != a[i]) continue;
			while (j - 1 > i)
			{
				swap(a[j], a[j - 1]);
				j--;
				ans++;
			}
			break;
		}
	}
	cout << ans << endl;

	return 0;
}