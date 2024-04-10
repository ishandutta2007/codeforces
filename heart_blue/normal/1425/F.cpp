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
const int N = 1e3 + 10;
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	int xy, yz, xyz;
	cout << "? 1 2" << endl;
	cin >> xy;
	cout << "? 1 3" << endl;
	cin >> xyz;
	cout << "? 2 3" << endl;
	cin >> yz;
	a[1] = xyz - yz;
	a[3] = xyz - xy;
	a[2] = xyz - a[1] - a[3];
	for (int i = 4; i <= n; i++)
	{
		printf("? %d %d", i - 1, i);
		cout << endl;
		cin >> a[i];
		a[i] -= a[i - 1];
	}
	cout << "!";
	for (int i = 1; i <= n; i++)
		cout << " " << a[i];
	cout << endl;
	return 0;
}