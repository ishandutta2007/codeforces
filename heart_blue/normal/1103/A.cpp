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
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 5e3 + 10;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int cnt0 = 0, cnt1 = 0;
	string str;
	cin >> str;
	for (auto &c : str)
	{
		if (c == '0')
		{
			if (cnt0 == 0) cout << 1 << ' ' << 1 << endl;
			else cout << 3 << ' ' << 1 << endl;
			cnt0 ^= 1;
		}
		else
		{
			if (cnt1 == 0) cout << 4 << ' ' << 3 << endl;
			else cout << 4 << ' ' << 1 << endl;
			cnt1 ^= 1;
		}
	}
	return 0;
}