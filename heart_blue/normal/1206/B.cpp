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
	int n;
	cin >> n;
	int neg = 0, pos = 0, zero = 0;
	LL ans = 0;
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		if (x > 0) ans += x - 1, pos++;
		else if (x == 0) zero++, ans++;
		else if (x < 0) ans += -1 - x, neg++;
	}
	
	if (neg % 2 == 1)
	{
		if (!zero)
			ans += 2;
	}
	cout << ans << endl;
	return 0;
}