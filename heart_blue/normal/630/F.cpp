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
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
LL gcd(LL n, LL m)
{
	return m == 0 ? n : gcd(m, n%m);
}
LL C(int n, int m)
{
	LL ret = 1;
	LL fact = 1;
	for (int i = 1; i <= m; i++) fact *= i;
	while (m--)
	{
		ret *= n--;
		LL g = gcd(ret, fact);
		ret /= g;
		fact /= g;
	}
	return ret / fact;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	cout << C(n, 5) + C(n, 6) + C(n, 7) << endl;
	return 0;
}