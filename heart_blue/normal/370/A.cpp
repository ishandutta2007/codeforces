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
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 1;
const int N = 1e6 + 10;
int a[110];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	if (a == c && b == d)
	{
		cout << "0 0 0" << endl;
		return 0;
	}
	if (a == c || b == d)
	{
		cout << "1 ";
	}
	else cout << "2 ";
	if (a - b == c - d || a + b == c + d)
	{
		cout << "1 ";
	}
	else if ((abs(a - b) - abs(c - d)) % 2 == 0 || (abs(a + b) - abs(c + d)) % 2 == 0)
	{
		cout << "2 ";
	}
	else
	{
		cout << "0 ";
	}
	cout << max(abs(a - c), abs(b - d)) << endl;
	return 0;
}