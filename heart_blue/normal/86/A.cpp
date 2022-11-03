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
int a[N];
vector<int> v[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	LL l, r;
	cin >> l >> r;
	LL o = 9;
	while (o < r)
	{
		o = o * 10 + 9;
	}
	l = max(l, (o + 1) / 10);
	LL mid = (o + 1) / 2;
	if (mid >= r) cout << r * (o - r) << endl;
	else if (mid <= l) cout << l * (o - l) << endl;
	else cout << mid * (o - mid) << endl;
	return 0;
}