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
#include <random>
#include <cassert>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e2 + 10;
char str[N][N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int k;
	cin >> k;
	if (k & 1)
	{
		puts("-1");
		return 0;
	}
	char w = 'w', h = 'b';
	for (int o = 0; o < k; o++)
	{
		swap(w, h);
		for (int i = 0; i * 2 < k; i++)
		{
			for (int j = 0; j * 2 < k; j++)
			{
				int o = 0;
				if ((i + j) & 1) o = w;
				else o = h;
				int x = i * 2;
				int y = j * 2;
				str[x][y] = str[x + 1][y] = str[x][y + 1] = str[x + 1][y + 1] = o;
			}
		}
		for (int i = 0; i < k; i++) puts(str[i]);
	}
	return 0;
}