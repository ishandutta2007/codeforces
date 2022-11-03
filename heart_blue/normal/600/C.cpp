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
const int N = 2e2 + 10;
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	string str;
	cin >> str;
	MEM(a, 0);
	for (auto &c : str) a[c]++;
	int ptr = 'z';
	for (int i = 'a'; i <= 'z'; i++)
	{
		if (a[i] % 2 == 0) continue;
		while (a[ptr] % 2 == 0) ptr--;
		a[i]++;
		a[ptr]--;
	}
	int key = 0;
	for (int i = 'a'; i <= 'z'; i++)
	{
		if (a[i] & 1) key = i;
		a[i] >>= 1;
		int o = a[i];
		while (o--) putchar(i);
	}
	if (key) putchar(key);
	for (int i = 'z'; i >= 'a'; i--)
	{
		while (a[i]--) putchar(i);
	}
	return 0;

}