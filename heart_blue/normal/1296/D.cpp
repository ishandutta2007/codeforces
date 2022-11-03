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
const int N = 3e5 + 10;
char str[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, a, b, k;
	cin >> n >> a >> b >> k;
	vector<int> v;
	while (n--)
	{
		int x;
		cin >> x;
		x %= a + b;
		if (x == 0) x = a + b;
		v.push_back((x - 1) / a);
	}
	sort(v.begin(), v.end());
	int ans = 0;
	for (auto& x : v)
	{
		k -= x;
		if (k >= 0) ans++;
		else break;
	}
	cout << ans << endl;
	return 0;
}