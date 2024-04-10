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
const int N = 7e2 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	string str;
	cin >> n >> str;
	int tot = 0;
	for (auto &c : str) tot += c-'0';
	if (tot == 0)
	{
		puts("YES");
		return 0;
	}
	for (int i = 1; i * 2 <= tot; i++)
	{
		if (tot % i) continue;
		int flag = 1;
		int sum = 0;
		for (int j = 0; j < n; j++)
		{
			sum += str[j] - '0';
			if (sum >= i)
			{
				if(sum > i)
				{
					flag = 0;
					break;
				}
				sum = 0;
			}
		}
		if (flag)
		{
			puts("YES");
			return 0;
		}
	}
	puts("NO");
	return 0;
}