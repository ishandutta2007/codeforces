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
const int N = 5e2 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	map<int, int> mc;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int sz;
		cin >> sz;
		while (sz--)
		{
			int x;
			cin >> x;
			mc[x]++;
		}
	}
	for (auto& p : mc)
	{
		if (p.second == n)
			cout << p.first << ' ';
	}
	return 0;
}