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
const int N = 2e3 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	LL tot = 1LL * n * (n + 1) / 2;
	LL ans1 = 0;
	int cnt[2] = { 1,0 };
	int sum = 0;
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		if (x > 0) x = 0;
		else x = 1;
		sum ^= x;
		cnt[sum]++;
		ans1 += cnt[sum ^ 1];
	}
	cout << ans1 << ' ' << tot - ans1 << endl;
	return 0;
}