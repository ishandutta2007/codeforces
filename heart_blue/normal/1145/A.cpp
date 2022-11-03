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
int a[N];
int check(int l, int r)
{
	int flag = 1;
	if (r == l) return 1;
	for (int i = l + 1; i <= r; i++)
	{
		if (a[i] < a[i - 1]) flag = 0;
	}
	if (flag) return r - l + 1;
	int mid = (l + r) / 2;
	return max(check(l, mid), check(mid + 1, r));
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	cout << check(1, n) << endl;
	return 0;
}