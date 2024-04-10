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
const int N = 1e7 + 10;
LL a[3][3];
void floyd()
{
	for (int k = 0; k < 3; k++)
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
			}
		}
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	LL x, y, z;
	cin >> x >> y >> z;
	MEM(a, 0x3f);
	a[0][1] = a[1][0] = x;
	a[0][2] = a[2][0] = y;
	a[1][2] = a[2][1] = z;
	a[0][0] = a[1][1] = a[2][2] = 0;
	floyd();
	cout << min(a[0][1] + a[1][2] + a[2][0], a[0][2] + a[2][1] + a[1][0]) << endl;
	return 0;
}