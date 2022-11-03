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
const int N = 1e5 + 10;
char str[20][20];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		for (int i = 1; i <= 9; i++)
		{
			scanf("%s", str[i] + 1);
		}
		str[1][1] = str[1][2];
		str[2][4] = str[2][3];
		str[3][7] = str[3][8];
		str[4][2] = str[4][3];
		str[5][5] = str[5][6];
		str[6][8] = str[6][9];
		str[7][3] = str[7][2];
		str[8][6] = str[8][5];
		str[9][9] = str[9][8];
		for (int i = 1; i <= 9; i++)
			puts(str[i] + 1);
	}
	return 0;
}