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
#include <iterator>
#include <complex>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(x, y) memset((x),(y),sizeof(x))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
int a[N];
void init()
{
	MEM(a, 0);
	for (int i = 2; i < N; i++)
	{
		if (a[i]) continue;
		for (int j = i + i; j < N; j += i) a[j] = 1;
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	init();
	int n;
	cin >> n;
	n++;
	if (n <= 3) cout << 1 << endl;
	else cout << 2 << endl;
	for (int i = 2; i <= n; i++)
	{
		cout << a[i] + 1 << ' ';
	}
	return 0;
}