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
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	LL n;
	cin >> n;
	if (n % 2 == 0)
	{
		cout << n/2 << endl;
		return 0;
	}
	for (int i = 2; 1LL * i*i <= n; i++)
	{
		if (n%i == 0)
		{
			cout << 1 + (n - i) / 2 << endl;
			return 0;
		}
	}
	cout << 1 << endl;
	return 0;
}