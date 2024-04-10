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
const int N = 2e5 + 10;
int getsum(string& str)
{
	int ret = 0;
	for (auto& c : str)
	{
		ret += c - '0';
	}
	return ret;
}
void getnext(string& str, int tot)
{
	int sum = 0;
	for (int i = 0; i < str.length(); i++)
	{
		sum += str[i] - '0';
		if (sum > tot)
		{
			str[i]++;
			for (int j = i + 1; j < str.length(); j++) str[j] = '0';
			for (int j = i; j > 0; j--)
			{
				if (str[j] > '9') str[j] -= 10, str[j - 1] ++;
			}
			if (str[0] > '9')
			{
				str[0] = '0';
				str = '1' + str;
			}
			return;
		}
	}
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		string str;
		int tot;
		cin >> str >> tot;
		LL cur = stoll(str);
		while (getsum(str) > tot)
		{
			getnext(str, tot);
		}
		printf("%lld\n", stoll(str) - cur);
	}
	return 0;
}