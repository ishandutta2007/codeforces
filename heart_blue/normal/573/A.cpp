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
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e6 + 10;
int a[N];
int gcd(int n, int m)
{
	return m == 0 ? n : gcd(m, n%m);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	int g = a[0];
	for (int i = 1; i < n; i++) g = gcd(a[i], g);
	for (int i = 0; i < n; i++) a[i] /= g;
	for (int i = 0; i < n; i++) while (a[i] % 2 == 0) a[i] /= 2;
	for (int i = 0; i < n; i++) while (a[i] % 3 == 0) a[i] /= 3;
	string ans = "Yes";
	for (int i = 0; i < n; i++)
	{
		if (a[i] != 1)
		{
			ans = "No";
			break;
		}
	}
	cout << ans << endl;
	return 0;
}