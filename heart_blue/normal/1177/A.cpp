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
const int N = 3e5 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	LL n;
	cin >> n;
	LL l = 1, r = 9, len = 1;
	while (1)
	{
		if (n > (r - l + 1)* len)
		{
			n -= (r - l + 1) * len;
			l = l * 10;
			r = r * 10 + 9;
			len++;
			continue;
		}
		n--;
		l += n / len;
		cout << to_string(l)[n % len] << endl;
		break;
	}
	return 0;
}