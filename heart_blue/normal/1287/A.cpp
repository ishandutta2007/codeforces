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
const LL INF = 1e9 + 7;
const int N = 5e5 + 20;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	cin >> ncase;
	while (ncase--)
	{
		string str;
		int n;
		cin >> n;
		cin >> str;
		int ans = 0;
		while (1)
		{
			int flag = 0;
			for (int i = str.length() - 1; i > 0; i--)
			{
				if (str[i] == 'P' && str[i - 1] == 'A')
				{
					str[i] = 'A';
					flag = 1;
				}
			}
			ans += flag;
			if (flag == 0) break;
		}
		cout << ans << endl;
	}
	return 0;
}