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
	int n, I;
	cin >> n >> I;
	I *= 8;
	map<int, int> mc;
	int maxv = 0;
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		mc[x]++;
		maxv = max(maxv, mc[x]);
	}
	vector<int> v;
	for (auto& p : mc) v.push_back(p.second);
	for (int o = 1; I >> o; o++)
	{
		int len = 1 << o;
		if (I / o < n) break;
		int tot = 0;
		for (int i = 0; i < v.size(); i++)
		{
			tot += v[i];
			if (i >= len) tot -= v[i - len];
			maxv = max(maxv, tot);
		}
	}
	cout << n - maxv << endl;
	return 0;
}