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
const int N = 2e3 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k;
	cin >> n >> k;
	cout << "YES" << endl;
	cout << string(n, '.') << endl;
	if (k & 1)
	{
		if (k <= n - 2)
		{
			cout << string((n - k) / 2, '.');
			cout << string(k, '#');
			cout << string((n - k) / 2, '.') << endl;
			cout << string(n, '.') << endl;
		}
		else
		{
			cout << '.' << string(n - 2, '#') << '.' << endl;
			k -= n - 2;
			cout << '.';
			cout << string(k / 2, '#');
			cout << string(n-k-2, '.');
			cout << string(k / 2, '#');
			cout << '.' << endl;
		}
		cout << string(n, '.') << endl;
	}
	else
	{
		cout << '.';
		cout << string(k / 2, '#');
		cout << string(n - k / 2 - 1, '.') << endl;
		cout << '.';
		cout << string(k / 2, '#');
		cout << string(n - k / 2 - 1, '.') << endl;
		cout << string(n, '.') << endl;
	}
	return 0;
}