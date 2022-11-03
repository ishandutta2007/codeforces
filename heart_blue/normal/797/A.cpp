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
const int N = 2e2 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k;
	cin >> n >> k;
	vector<int> v;
	for (int i = 2; i <= n; i++)
	{
		while (n%i == 0) n /= i, v.push_back(i);
	}
	while (v.size() > k)
	{
		v[v.size() - 2] *= v.back();
		v.pop_back();
	}
	if (v.size() != k) cout << -1 << endl;
	else for (auto &x : v) cout << x << ' ';
	return 0;
}