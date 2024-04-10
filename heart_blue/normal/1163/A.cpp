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
const int N = 2e5 + 10;
int flag[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ans = 0;
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n && k > 0; i += 2, k--)
	{
		flag[i] = 1;
	}
	for (int i = 2; i <= n && k > 0; i += 2, k--)
	{
		flag[i] = 1;
	}
	flag[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		if (flag[i] == 0 && flag[i - 1] == 1)
			ans++;
	}
	cout << ans << endl;
	return 0;
}