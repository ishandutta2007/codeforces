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

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int a[10];
	MEM(a, 0x3f);
	int inf = a[0];
	int n;
	cin >> n;
	while (n--)
	{
		int x;
		string str;
		cin >> x >> str;
		int o = 0;
		for (auto& c : str) o |= 1 << (c - 'A');
		a[o] = min(a[o], x);
	}
	for (int i = 1; i < 8; i++)
	{
		for (int j = 1; j < 8; j++)
		{
			a[i | j] = min(a[i | j], a[i] + a[j]);
		}
	}
	if (a[7] == inf) a[7] = -1;
	cout << a[7] << endl;
	return 0;
}