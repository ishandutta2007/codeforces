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
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
char str[N];

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%s", str);
	stack<int> s;
	for (int i = 0; str[i]; i++)
	{
		if (str[i] == '0')
		{
			if (!s.empty())
			{
				int x = s.top();
				s.pop();
				str[x] = '1';
			}
		}
		else
			s.push(i);
	}
	while (!s.empty())
	{
		int x = s.top();
		s.pop();
		str[x] = '0';
	}
	puts(str);
	return 0;
}