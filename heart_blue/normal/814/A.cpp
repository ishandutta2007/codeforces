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
const int N = 5e3 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k;
	cin >> n >> k;
	vector<int> v(n), v2(k);
	for (auto &x : v) cin >> x;
	for (auto &x : v2) cin >> x;
	sort(v2.rbegin(), v2.rend());
	k = 0;
	for (auto &x : v) if (x == 0) x = v2[k++];
	int flag = 0;
	for (int i = 1; i < n; i++)
	{
		if (v[i] < v[i - 1])
		{
			flag = 1;
			break;
		}
	}
	if (flag) puts("Yes");
	else puts("No");
	return 0;
}