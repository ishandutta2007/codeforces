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
#include <iterator>
#include <complex>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e2 + 10;
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	int sum = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		sum += a[i];
	}
	if (sum != 0)
	{
		cout << "YES" << endl;
		cout << 1 << endl;
		cout << 1 << ' ' << n << endl;
		return 0;
	}
	for (int i = 1; i <= n; i++)
	{
		sum += a[i];
		if (sum != 0)
		{
			cout << "YES" << endl;
			if (i != n) cout << 2 << endl;
			else cout << 1 << endl;
			cout << 1 << ' ' << i << endl;
			if (i != n) cout << i + 1 << ' ' << n << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
	return 0;
}