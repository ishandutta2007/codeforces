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
const int N = 4e5 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	LL h, r;
	cin >> r >> h;
	h *= 2, r *= 2;
	if (h < r / 2)
	{
		cout << 1 << endl;
		return 0;
	}
	int ans = h / r;
	if (h / (r / 2) % 2 == 1) ans++;
	h -= ans * r;
	ans *= 2;
	if (r*r / 4 * 3 <= (h + r)*(h + r)) ans++;
	cout << ans << endl;
	return 0;
}