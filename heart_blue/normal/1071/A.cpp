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
const int N = 1e5 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int a, b;
	cin >> a >> b;
	LL sum = 0;
	int tot = 0;
	for (int i = 1; i <= a + b; i++)
	{
		sum += i;
		if (sum <= a + b)
		{
			tot = i;
		}
		else break;
	}
	vector<int> v1, v2;
	for (int i = tot; i >= 1; i--)
	{
		if (a >= i)
		{
			a -= i;
			v1.push_back(i);
		}
		else
		{
			v2.push_back(i);
		}
	}
	printf("%d\n", v1.size());
	for (auto &x : v1) printf("%d ", x);
	puts("");
	printf("%d\n", v2.size());
	for (auto &x : v2) printf("%d ", x);
	puts("");
	return 0;
}