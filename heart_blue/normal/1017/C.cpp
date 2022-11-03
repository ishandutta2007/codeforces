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
const int N = 1e5 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	int k = 1;
	int minv = INF;
	for (int i = 1; i <= n; i++)
	{
		int tot = i + (n + i - 1) / i;
		if (tot < minv) minv = tot, k = i;
	}
	vector<int> v;
	for (int i = 1; i <= n; i++) v.push_back(i);
	while (!v.empty())
	{
		vector<int> tmp;
		int o = k;
		while (!v.empty() && o > 0)
		{
			o--;
			tmp.push_back(v.back());
			v.pop_back();
		}
		reverse(tmp.begin(), tmp.end());
		for (auto &x : tmp) cout << x << ' ';
	}
	return 0;
}