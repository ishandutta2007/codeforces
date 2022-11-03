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
const int N = 1e5 + 10;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	cin >> ncase;
	while (ncase--)
	{
		int l, r;
		cin >> l >> r;
		if ((r - l) & 1)
		{
			int ans = (r - l + 1) / 2;
			if (l & 1) ans *= 1;
			else ans *= -1;
			cout << ans << endl;
		}
		else
		{
			int ans = (r - l + 1) / 2;
			if (l & 1) ans *= 1;
			else ans *= -1;
			if (r & 1) ans += -r;
			else ans += r;
			cout << ans << endl;
		}
	}
	return 0;
}