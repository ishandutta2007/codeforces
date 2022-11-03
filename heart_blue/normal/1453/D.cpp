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
		LL n;
		scanf("%lld", &n);
		if (n & 1)
		{
			puts("-1");
			continue;
		}
		vector<int> v;
		n >>= 1;
		for (int i = 62; i >= 0; i--)
		{
			LL o = 1LL << (i + 1);
			o--;
			while (n >= o)
			{
				for (int j = 0; j < i; j++)
					v.push_back(0);
				v.push_back(1);
				n -= o;
			}
		}
		v.pop_back();
		v.insert(v.begin(), 1);
		printf("%d\n", v.size());
		for (auto& x : v) printf("%d ", x);
		puts("");
	}

	return 0;
}