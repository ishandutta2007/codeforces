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
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e2 + 10;
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k;
	cin >> n >> k;
	MEM(a, 0);
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		a[x]++;
	}
	int ans = 0;
	while (a[k] != n)
	{
		ans++;
		for (int i = k - 1; i > 0; i--)
		{
			if (a[i])
			{
				a[i]--;
				a[i + 1]++;
			}
		}
	}
	cout << ans << endl;
	return 0;
}