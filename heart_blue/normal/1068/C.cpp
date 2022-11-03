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
const int N = 5e5 + 10;
vector<int> v[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	int cur = 1;
	for (int i = 1; i <= n; i++)
		v[i].push_back(cur++);
	while (m--)
	{
		int x, y;
		cin >> x >> y;
		v[x].push_back(cur);
		v[y].push_back(cur);
		cur++;
	}
	for (int i = 1; i <= n; i++)
	{
		cout << v[i].size() << endl;
		for (auto& x : v[i])
		{
			cout << i << ' ' << x << endl;
		}
	}
	return 0;
}