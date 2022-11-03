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
const int N = 1e2 + 10;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	if (n <= 1)
	{
		cout << 1 << endl;
		return 0;
	}
	else if (n == 2 || n == 4 || n == 5)
	{
		cout << 3 << endl;
		return 0;
	}
	for (int i = 5; i <= 100; i++)
	{
		int tot = 0;
		if (i & 1) tot = i*i / 2 + 1;
		else
		{
			int x = i / 2 - 1;
			x = x*x / 2 + x % 1;
			tot = 4 * x;
		}
		if (tot >= n)
		{
			cout << i << endl;
			break;
		}
	}
	return 0;
}