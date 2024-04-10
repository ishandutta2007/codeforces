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

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	LL ans = 1e18;
	LL l = 3, r = 1e18;
	for (int i = 2; i <= 26; i++)
	{
		cout << "? 1 " << i << endl;
		LL ret1;
		cin >> ret1;
		cout << "? " << i << " 1" << endl;
		LL ret2;
		cin >> ret2;
		if (ret1 == -1)
		{
			cout << "! " << i - 1 << endl;
			break;
		}
		if (ret1 != ret2)
		{
			cout << "! " << ret1 + ret2 << endl;
			break;
		}
	}
	return 0;
}