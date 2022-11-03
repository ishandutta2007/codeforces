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
#include <random>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e3 + 10;
int cnt[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	int tot = (n + 1) / 2;
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		cnt[x]++;
	}
	int ans = 0;
	for (int i = 1; i <= m && tot > 0; i++)
	{
		while (cnt[i] > 1 && tot > 0)
		{
			cnt[i] -= 2;
			ans += 2;
			tot--;
		}
	}
	for (int i = 1; i <= m && tot > 0; i++)
	{
		while (cnt[i] && tot)
		{
			cnt[i] --;
			tot--;
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}