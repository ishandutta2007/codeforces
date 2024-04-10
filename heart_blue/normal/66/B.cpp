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

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	int a[N];
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		int k1 = i, k2 = i;
		for (int j = i - 1; j >= 0; j--)
		{
			if (a[j] <= a[j + 1]) k1 = j;
			else break;
		}
		for (int j = i + 1; j < n; j++)
		{
			if (a[j] <= a[j - 1]) k2 = j;
			else break;
		}
		ans = max(ans, k2 - k1 + 1);
	}
	cout << ans << endl;
	return 0;
}