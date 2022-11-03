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
const int N = 2e2 + 10;
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	MEM(a, 0);
	a['A'] = 'A';
	a['b'] = 'd';
	a['d'] = 'b';
	a['H'] = 'H';
	a['I'] = 'I';
	a['M'] = 'M';
	a['O'] = 'O';
	a['o'] = 'o';
	a['p'] = 'q';
	a['q'] = 'p';
	a['T'] = 'T';
	a['U'] = 'U';
	a['V'] = 'V';
	a['v'] = 'v';
	a['W'] = 'W';
	a['w'] = 'w';
	a['X'] = 'X';
	a['x'] = 'x';
	a['Y'] = 'Y';
	string str;
	cin >> str;
	int l = 0;
	int r = str.length() - 1;
	while (l <= r)
	{
		if (a[str[l]] == str[r] && a[str[r]] == str[l])
		{
			l++, r--;
			continue;
		}
		cout << "NIE" << endl;
		return 0;
	}
	cout << "TAK" << endl;
	return 0;
}