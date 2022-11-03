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
#define MEM(x, y) memset((x),(y),sizeof(x))
const int INF = 1e9 + 7;
const int N = 1e4 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	string str;
	cin >> str;
	cout << str[0];
	int flag = 0;
	for (int i = 1; i < str.length(); i++)
	{
		if (!(i + 2 >= str.length() || flag == 1))
		{
			if (str.substr(i, 2) == "at")
			{
				cout << "@";
				i++;
				flag = 1;
				continue;
			}
		}
		if (i + 3 < str.length())
		{
			if (str.substr(i, 3) == "dot")
			{
				cout << '.';
				i += 2;
				continue;
			}
		}
		cout << str[i];
	}
	return 0;
}