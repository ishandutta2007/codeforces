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
const LL INF = 1e8 + 7;
const int N = 3e2 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k;
	string str;
	cin >> n >> k >> str;

	if (str.length() == 1)
	{
		if (k > 0) str[0] = '0';
		cout << str << endl;
		return 0;
	}
	for (int i = 0; k > 0 && i < str.length(); i++)
	{
		if (i == 0)
		{
			if (str[i] != '1')
			{
				str[i] = '1';
				k--;
			}
			continue;
		}
		if (str[i] > '0')
		{
			str[i] = '0';
			k--;
		}
	}
	cout << str << endl;
	return 0;
}