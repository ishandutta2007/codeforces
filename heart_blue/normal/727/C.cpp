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
const int N = 2e5 + 10;
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	int sum12, sum23, sum13;
	cout << "? 1 2" << endl;
	cin >> sum12;
	cout << "? 2 3" << endl;
	cin >> sum23;
	cout << "? 1 3" << endl;
	cin >> sum13;
	int tot = sum12 + sum23 + sum13;
	a[1] = tot / 2 - sum23;
	a[2] = tot / 2 - sum13;
	a[3] = tot / 2 - sum12;
	for (int i = 4; i <= n; i++)
	{
		cout << "? " << i - 1 << ' ' << i << endl;
		cin >> a[i];
		a[i] -= a[i - 1];
	}
	cout << "!";
	for (int i = 1; i <= n; i++)
	{
		cout << ' ' << a[i];
	}
	cout << endl;
	return 0;
}