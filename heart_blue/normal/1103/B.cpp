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
#include <chrono>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
int n = 500;
bool ask(int x, int y)
{
	cout << "? " << x << ' ' << y << endl;
	//return x % n >= y % n;
	char c;
	cin >> c;
	return c == 'x';
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	string str;
	while (cin >> str)
	{
		if (str == "end") break;
		if (str == "mistake") break;
		//cin >> n;
		int x = 1;
		while (!ask(x, 2 * x)) x *= 2;
		int l = 1, r = x;
		while (l <= r)
		{
			int mid = (l + r) / 2;
			if (ask(mid, mid * 2)) x = 2 * mid, r = mid - 1;
			else l = mid + 1;
		}
		if (x == 2)
		{
			if (ask(2, 3)) x = 1;
			else x = 2;
		}
		else if (!ask(x - 1, x)) x--;
		cout << "! " << x << endl;
	}
	return 0;
}