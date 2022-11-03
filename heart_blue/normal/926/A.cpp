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
const int N = 1e5 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	LL l, r;
	cin >> l >> r;
	vector<LL> vp;
	for (LL x = 1; x <= 2 * INF; x *= 2)
	{
		LL o = x;
		while (o <= INF * 2)
		{
			vp.push_back(o);
			o *= 3;
		}
	}
	sort(vp.begin(), vp.end());
	cout << upper_bound(vp.begin(), vp.end(), r) - lower_bound(vp.begin(), vp.end(), l) << endl;
	return 0;
}