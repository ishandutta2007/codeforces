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
const int N = 1e6 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n;
		cin >> n;
		string str;
		cin >> str;
		int l = -1, r = -1;
		for (int i = 0; i < n; i++)
		{
			int o = 0;
			for (int j = i; j < n; j++)
			{
				if (str[j] == 'a') o++;
				else o--;
				if (o == 0)
				{
					l = i + 1;
					r = j + 1;
				}
			}
		}
		cout << l << ' ' << r << endl;
	}
	return 0;
}