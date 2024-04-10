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
const int N = 5e3 + 10;
int flag[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	LL tot;
	int n;
	cin >> tot >> n;
	tuple<LL, LL, int> ans = { INF*INF,0, 0 };
	for (int i = 1; i <= n; i++)
	{
		LL x;
		cin >> x;
		ans = min(ans, { tot%x, tot / x, i });
	}
	cout << get<2>(ans) << ' ' << get<1>(ans) << endl;
	return 0;
}