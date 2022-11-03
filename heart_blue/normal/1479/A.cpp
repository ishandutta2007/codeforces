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
const int N = 2e5 + 10;
int a[N];
int ask(int n)
{
	if (a[n] != 0) return a[n];
	cout << "? " << n << endl;
	cin >> a[n];
	return a[n];
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	int l = 0, r = n + 1;
	a[l] = INF;
	a[r] = INF + 1;
	l = 1, r = n;
	while (l <= r)
	{
		int mid = (l + r) / 2;
		int a = ask(mid - 1);
		int b = ask(mid);
		int c = ask(mid + 1);
		if (a > b && b < c)
		{
			cout << "! " << mid << endl;
			return 0;
		}
		if (b > a) r = mid - 1;
		else l = mid + 1;
	}
	return 0;
}