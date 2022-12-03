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
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e3 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	int l = 1, r = n - 1;
	int ans = -1;
	int c = 0;
	while (l < r)
	{
		int key = ((n - r) + (n - l)) / 2;
		cout << "+ " << key << endl;
		int res;
		cin >> res;
		int kl = INF, kr = 0;
		for (int i = l; i <= r; i++)
		{
			if ((i + key) / n == res - c)
			{
				kl = min(kl, i);
				kr = max(kr, i);
			}
		}
		c = res;
		l = (kl + key) % n;
		r = (kr + key) % n;
	}
	cout << "! " << c * n + r << endl;
	return 0;
}