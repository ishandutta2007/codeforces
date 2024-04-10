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
const int N = 1e2 + 10;

int a[N][N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	vector<int> v(5);
	for (int i = 0; i < 5; i++) v[i] = i + 1;
	int m;
	cin >> m;
	while (m--)
	{
		int x, y;
		cin >> x >> y;
		a[x][y] = a[y][x] = 1;
	}
	int flag = 0;
	do
	{
		int cnt0 = 0, cnt1 = 0;
		for (int i = 0; i < 3; i++)
		{
			for (int j = i + 1; j < 3; j++)
			{
				int x = v[i];
				int y = v[j];
				if (a[x][y]) cnt1++;
				else cnt0++;
			}
		}
		if (cnt0 == 3 || cnt1 == 3)
		{
			flag = 1;
			break;
		}
		
	} while (next_permutation(v.begin(), v.end()));
	if (flag) puts("WIN");
	else puts("FAIL");
	return 0;
}