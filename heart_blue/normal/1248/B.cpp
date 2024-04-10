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
	int n;
	cin >> n;
	LL sum1 = 0, sum2 = 0;
	vector<int> v(n);
	for (auto& x : v) cin >> x;
	sort(v.begin(), v.end());
	int l = 0, r = n - 1;
	while (l < r)
	{
		sum1 += v[l++];
		sum2 += v[r--];
	}
	if (l == r) sum2 += v[l];
	cout << sum1 * sum1 + sum2 * sum2 << endl;
	return 0;
}