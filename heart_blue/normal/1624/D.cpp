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
int sz[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		map<char, int> mc;
		int n, k;
		scanf("%d%d", &n, &k);
		string str;
		cin >> str;
		for (auto& c : str)
		{
			mc[c]++;
		}
		int tot = 0;
		for (auto& p : mc)
		{
			tot += p.second / 2;
			p.second &= 1;
		}
		int ans = 0;
		for (int i = 0; i <= tot / k; i++)
		{
			int rest = n - i * k * 2;
			if (rest >= k) ans = i * 2 + 1;
			else ans = i * 2;
		}
		printf("%d\n", ans);
	}
	return 0;
}