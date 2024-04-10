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
#include <cassert>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 3e5 + 10;
int a[N];
int b[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) cin >> b[i];
	vector<pair<int, int>> ans;
	for (int i = n; i >= 1; i--)
	{
		for (int j = i; j >= 1; j--)
		{
			if (b[j] != a[i]) continue;
			for (int k = j; k < i; k++)
			{
				ans.emplace_back(k, k + 1);
				swap(b[k], b[k + 1]);
			}
			break;
		}
	}
	printf("%d\n", ans.size());
	for (auto& p : ans)
		printf("%d %d\n", p.first, p.second);

	return 0;
}