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
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	cout << n + 1 << endl;
	int sum = 0;
	for (int i = n - 1; i >= 0; i--)
	{
		int x = (a[i] + sum) % n;
		int o = 0;
		if (x < i) o = i - x;
		else o = i + n - x;
		cout << 1 << ' ' << i + 1 << ' ' << o << endl;
		sum += o;
	}
	cout << 2 << ' ' << n << ' ' << n << endl;
	return 0;
}