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
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 4e3 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k;
	cin >> n >> k;
	string str;
	cin >> str;
	int c = 0;
	str = "0" + str;
	int key = -1;
	int flag = 0;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == '.')
		{
			flag = 1;
			continue;
		}
		if (flag && str[i] >= '5')
		{
			key = i;
			break;
		}
	}
	if (key != -1)
	{
		str = str.substr(0, key + 1);
		c = 1;
		while (k-- && c)
		{
			str.pop_back();
			if (str.back() == '.')
			{
				str.pop_back();
				str.back()++;
				for (int i = str.length() - 1; i >= 0; i--)
				{
					if (str[i] > '9') str[i] -= 10, str[i - 1]++;
				}
				break;
			}
			str.back()++;
			if (str.back() == '5') c = 1;
			else c = 0;
		}
	}
	if (str.front() == '0') str = str.substr(1);
	cout << str << endl;
	return 0;
}