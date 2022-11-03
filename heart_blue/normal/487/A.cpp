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
const int N = 5e2 + 10;
int check(int h1, int a1, int d1, int h2, int a2, int d2)
{
	for (int i = 1; i < N; i++)
	{
		h1 -= max(0, a2 - d1);
		h2 -= max(0, a1 - d2);
		if (h2 <= 0)
		{
			if (h1 > 0) return 0;
			else return abs(h1) + 1;
		}
	}
	return INF;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int hp1, atk1, def1;
	int hp2, atk2, def2;
	int h, a, d;
	int ans = INF;
	cin >> hp1 >> atk1 >> def1;
	cin >> hp2 >> atk2 >> def2;
	cin >> h >> a >> d;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			LL k = check(hp1, atk1 + i, def1 + j, hp2, atk2, def2);
			ans = min(1LL * ans, k*h + a*i + d*j);
		}
	}
	cout << ans << endl;
	return 0;
}