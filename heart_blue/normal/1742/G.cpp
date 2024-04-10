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
const int N = 3e5 + 10;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n;
		scanf("%d", &n);
		vector<int> v(n);
		for (auto& x : v)
			scanf("%d", &x);
		int mask = (1LL << 31) - 1;
		for (int i = 0; i < v.size(); i++)
		{
			if (mask == 0) break;
			int id = i;
			for (int j = i; j < v.size(); j++)
			{
				if ((v[j] & mask) > (v[id] & mask))
				{
					id = j;
				}
			}
			if ((v[id] & mask) == 0) break;
			swap(v[id], v[i]);
			mask ^= v[i] & mask;
		}
		for (auto& x : v)
			printf("%d ", x);
		puts("");
	}
	return 0;
}