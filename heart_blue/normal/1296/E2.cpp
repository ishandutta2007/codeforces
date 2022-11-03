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
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	string str;
	cin >> n >> str;
	vector<int> ans;
	int maxv = 0;
	for (auto& c : str)
	{
		int o = 0;
		for (int i = c + 1; i <= 'z'; i++)
		{
			o |= a[i];
		}
		int key = -1;
		for (int i = 0; i < 26; i++)
		{
			if (a[c] >> i & 1)
			{
				if (o >> i & 1) continue;
				else
				{
					key = i;
					break;
				}
			}
		}
		if (key == -1)
		{
			for (int i = 0; i < 26; i++)
			{
				if (o >> i & 1) continue;
				else
				{
					key = i;
					break;
				}
			}
		}
		a[c] |= 1 << key;
		ans.push_back(key);
		maxv = max(maxv, key);
	}
	printf("%d\n", maxv + 1);
	for (auto& x : ans)
		printf("%d ", x + 1);
	return 0;
}