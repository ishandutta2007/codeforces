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
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	string str;
	map<int, int> ms;
	for (int i = 0; i < n; i++)
	{
		cin >> str;
		int l = 0, r = 0;
		for (int j = 0; j < m; j++)
		{
			if (str[j] == 'G') l = j;
			if (str[j] == 'S') r = j;
		}
		if (r < l)
		{
			cout << -1 << endl;
			return 0;
		}
		ms[r - l] = 1;
	}
	cout << ms.size() << endl;
	return 0;
}