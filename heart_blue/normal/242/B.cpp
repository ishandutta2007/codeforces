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
const int N = 2e5 + 10;
int l[N], r[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	int x, y;
	x = 1, y = 0;
	int key = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> l[i] >> r[i];
		if (r[i] - l[i] > y - x)
		{
			y = r[i];
			x = l[i];
			key = i;
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (x <= l[i] && y >= r[i]) continue;
		key = -2;
		break;
	}
	key++;
	cout << key << endl;
	return 0;
}