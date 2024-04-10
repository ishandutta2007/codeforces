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
#include <iterator>
#include <complex>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e3 + 10;
bool check(string &str, int p, int n)
{
	int l = p;
	int r = p + n;
	while (n--)
	{
		if (str[r] == '*') break;
		if (str[l++] != str[r++]) return false;
	}
	return true;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	string str;
	cin >> str;
	int x;
	cin >> x;
	str += string(x, '*');
	x = (x + 1) / 2;
	int l = str.length();
	for (int n = str.length() / 2; n >= x; n--)
	{
		for (int i = 0; i + 2 * n <= l; i++)
		{
			if (check(str, i, n))
			{
				cout << n * 2 << endl;
				return 0;
			}
		}
	}
	return 0;
}