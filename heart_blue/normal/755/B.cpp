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
	int n, m;
	cin >> n >> m;
	map<string, int> ms;
	string str;
	for (int i = 1; i <= n; i++)
	{
		cin >> str;
		ms[str] = 1;
	}
	int k = 0;
	for (int i = 1; i <= m; i++)
	{
		cin >> str;
		if (ms.count(str)) k++;
	}
	n -= k;
	m -= k;
	if (k & 1) n++;
	if (n <= m) cout << "NO" << endl;
	else cout << "YES" << endl;
	return 0;
}