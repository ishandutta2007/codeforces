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
const int N = 2e5 + 10;
vector<int> v[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	LL n, m, k;
	cin >> n >> m >> k;
	if (k < n)
	{
		cout << k + 1 << ' ' << 1 << endl;
		return 0;
	}
	k -= n - 1;
	int row = n - (k - 1) / (m - 1);
	int col = (k - 1) % (m - 1);
	if ((n - row) % 2 == 1) col = m - col;
	else col += 2;
	cout << row << ' ' << col << endl;
	return 0;
}