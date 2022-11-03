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

int sum(int x)
{
	int ret = 0;
	while (x)
	{
		ret += x / 5;
		x /= 5;
	}
	return ret;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	int key = 0;
	for (int i = 5; ; i+=5)
	{
		int o = sum(i);
		if (o >= n)
		{
			if (o == n) key = i;
			break;
		}
	}
	if (key == 0)
	{
		cout << key << endl;
	}
	else
	{
		cout << 5 << endl;
		for (int i = 0; i < 5; i++)
		{
			cout << key + i << ' ';
		}
		cout << endl;
	}
	return 0;
}