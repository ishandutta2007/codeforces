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
	int n;
	cin >> n;
	int mid = (n + 1) / 2;
	int sum1 = 0, sum2 = 0;
	while (n--)
	{
		int x;
		cin >> x;
		if (x > 0) sum1++;
		else if (x < 0) sum2++;
	}
	if (sum1 >= mid) cout << 1 << endl;
	else if (sum2 >= mid) cout << -1 << endl;
	else cout << 0 << endl;
	return 0;
}