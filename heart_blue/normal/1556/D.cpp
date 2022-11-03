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
const int N = 3e4 + 10;
int a[N];
int ask(int i, int j)
{
	cout << "or " << i << " " << j << endl;
	int x;
	cin >> x;
	cout << "and " << i << " " << j << endl;
	int y;
	cin >> y;
	return x + y;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k;
	cin >> n >> k;
	LL s12 = ask(1, 2);
	LL s13 = ask(1, 3);
	LL s23 = ask(2, 3);
	LL sum = (s12 + s13 + s23) / 2;
	a[1] = sum - s23;
	a[2] = sum - s13;
	a[3] = sum - s12;
	for (int i = 4; i <= n; i++)
	{
		a[i] = ask(1, i) - a[1];
	}
	sort(a + 1, a + n + 1);
	cout << "finish " << a[k] << endl;
	return 0;
}