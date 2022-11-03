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
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e6 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	LL h1, h2;
	cin >> h1 >> h2;
	int a, b;
	cin >> a >> b;
	h1 += 8 * a;
	if (h1 >= h2)
	{
		cout << 0 << endl;
		return 0;
	}
	h1 -= 12 * b;
	for (int i = 1; i < N; i++)
	{
		h1 += 12 * a;
		if (h1 >= h2)
		{
			cout << i << endl;
			return 0;
		}
		h1 -= 12 * b;
	}
	cout << -1 << endl;
	return 0;
}