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
const int N = 2e5 + 10;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	vector<int> v(n);
	for (auto& x : v)
		scanf("%d", &x);
	sort(v.begin(), v.end());
	map<int, int> mc1, mc2;
	for (auto& x : v)
	{
		for (int i = -1; i <= 1; i++)
		{
			if (!mc1.count(x + i))
			{
				mc1[x + i] = 1;
				break;
			}
		}
		int key = x + 1;
		for (int i = -1; i <= 1; i++)
		{
			if (mc2.count(x + i))
			{
				key = x + i;
				break;
			}
		}
		mc2[key] = 1;
	}
	cout << mc2.size() << ' ' << mc1.size() << '\n';
	return 0;
}