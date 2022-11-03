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
const int N = 1e6 + 10;
bool check(int n, int p)
{
	for (int i = 2; i * i <= n; i++)
	{
		if (n%i == 0 && i <= p) return false;
	}
	return true;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, a, b;
	cin >> n >> a >> b;
	a--, b--;
	int ans = 0;
	while (n > 2)
	{
		ans++;
		if (a / 2 == b / 2)
		{
			cout << ans << endl;
			return 0;
		}
		n >>= 1;
		a >>= 1;
		b >>= 1;
	}
	cout << "Final!" << endl;
	return 0;
}