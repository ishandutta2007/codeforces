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
const LL INF = 1e9 + 7;
const int N = 2e2 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	if (n < 4)
	{
		cout << "NO" << endl;
		return 0;
	}
	cout << "YES" << endl;
	if (n == 4)
	{
		cout << "1 * 2 = 2" << endl;
		cout << "2 * 3 = 6" << endl;
		cout << "6 * 4 = 24" << endl;
		return 0;
	}
	if (n == 5)
	{
		cout << "5 + 4 = 9" << endl;
		cout << "9 + 3 = 12" << endl;
		cout << "12 * 2 = 24" << endl;
		cout << "24 * 1 = 24" << endl;
		return 0;
	}
	cout << "2 * 3 = 6" << endl;
	cout << "6 * 4 = 24" << endl;
	cout << "6 - 5 = 1" << endl;
	cout << "1 - 1 = 0" << endl;
	for (int i = 7; i <= n; i++)
	{
		cout << i << " * 0 = 0\n";
	}
	cout << "24 + 0 = 24" << endl;
	return 0;
}