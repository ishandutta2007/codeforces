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
const int N = 1e3 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int w, h;
	int w1, h1;
	int w2, h2;
	cin >> w >> h;
	cin >> w1 >> h1;
	cin >> w2 >> h2;
	for (int i = h; i >= 0; i--)
	{
		w += i;
		if (i == h1)
		{
			w = max(0, w - w1);
		}
		if (i == h2)
		{
			w = max(0, w - w2);
		}
	}
	cout << w << endl;
	return 0;
}