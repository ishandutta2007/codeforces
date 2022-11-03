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
const int N = 1e4 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	LL n, a, b, c;
	cin >> n >> a >> b >> c;
	LL ans = INF*INF;
	for (int i = 0; i <= 4; i++)
	{
		for (int j = 0; j <= 4; j++)
		{
			for (int k = 0; k <= 4; k++)
			{
				if ((n + i + j * 2 + k * 3) % 4 == 0)
				{
					ans = min(ans, i*a + j*b + k*c);
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}