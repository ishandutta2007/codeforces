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
const int N = 2e3 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int l, r;
	cin >> l >> r;
	int ans = -1;
	for (int i = l; i <= r; i++)
	{
		string str = to_string(i);
		sort(str.begin(), str.end());
		int flag = 1;
		for (int j = 0; j + 1 < str.length(); j++)
		{
			if (str[j] == str[j + 1])
			{
				flag = 0;
				break;
			}
		}
		if (flag) cout << i << endl, exit(0);
	}
	cout << ans << endl;
	return 0;
}