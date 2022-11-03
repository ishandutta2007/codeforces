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
LL v[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	LL a, b;
	cin >> n >> a >> b;
	LL sum = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> v[i];
		sum += v[i];
	}
	sort(v + 2, v + n + 1);
	for (int i = n; i >= 1; i--)
	{
		if (a*v[1] >= b * sum)
		{
			cout << n - i << endl;
			return 0;
		}
		sum -= v[i];
	}
	return 0;
}