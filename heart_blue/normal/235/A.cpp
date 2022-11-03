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
const int N = 1e5 + 10;

LL gcd(LL n, LL m)
{
	return m == 0 ? n : gcd(m, n%m);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	LL ans = 0;
	cin >> n;
	for (int i = 0; i < 200; i++)
	{
		for (int j = i; j < 200; j++)
		{
			for (int k = j; k < 200; k++)
			{
				LL a = n - i;
				LL b = n - j;
				LL c = n - k;
				if (c <= 0) break;
				LL lcm = a*b / gcd(a, b);
				lcm = lcm*c / gcd(lcm, c);
				ans = max(ans, lcm);
			}
		}
	}
	cout << ans << endl;
	return 0;
}