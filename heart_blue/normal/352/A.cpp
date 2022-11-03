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

const int INF = 1e5 + 7;
const int N = 1e3 + 10;


int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	int n;
	int d0, d5;
	cin >> n;
	d0 = d5 = 0;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		if (x == 0) d0++;
		else d5++;
	}
	if (d0 == 0)
	{
		cout << -1 << endl;
	}
	else if (d5 < 9)
	{
		cout << 0 << endl;
	}
	else
	{
		for (int i = 0; i < d5 / 9 * 9; i++) cout << 5;
		for (int i = 0; i < d0; i++) cout << 0;
		cout << endl;
	}
	return 0;
}