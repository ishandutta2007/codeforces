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
const int N = 2e5 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	cin >> ncase;
	while (ncase--)
	{
		int n, k;
		cin >> n >> k;
		vector<int> v1(n), v2(n);
		for (auto& x : v1) cin >> x;
		for (auto& x : v2) cin >> x;
		while (k--)
		{
			sort(v1.rbegin(), v1.rend());
			sort(v2.begin(), v2.end());
			int x = v1.back();
			int y = v2.back();
			if (x >= y) break;
			v1.pop_back();
			v2.pop_back();
			v1.push_back(y);
			v2.push_back(x);
		}
		int sum = 0;
		for (auto& x : v1)
			sum += x;
		cout << sum << endl;
	}
	return 0;
}