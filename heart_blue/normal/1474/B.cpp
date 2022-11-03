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
int flag[N];
vector<int> v;
void init()
{
	for (int i = 2; i < N; i++)
	{
		if (flag[i]) continue;
		v.push_back(i);
		for (int j = i + i; j < N; j += i) flag[j] = 1;
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	init();
	scanf("%d", &ncase);
	while (ncase--)
	{
		int d;
		scanf("%d", &d);
		int x = *lower_bound(v.begin(), v.end(), d + 1);
		int y = *lower_bound(v.begin(), v.end(), d + x);
		printf("%d\n", x * y);
	}
	return 0;
}