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
#include <cassert>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 3e5 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int mask1 = 0b11111110000000;
	int mask2 = 0b00000001111111;
	cout << "?";
	for (int i = 1; i <= 100; i++)
	{
		cout << " " << i;
	}
	cout << endl;
	int x1, x2;
	cin >> x1;
	cout << "?";
	for (int i = 1; i <= 100; i++)
	{
		cout << " " << (i << 7);
	}
	cout << endl;
	cin >> x2;
	cout << "! " << ((x1 & mask1) | (x2 & mask2)) << endl;
	return 0;
}