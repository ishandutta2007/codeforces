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
const int N = 2e5 + 10;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		string str;
		cin >> str;
		int L, R, U, D;
		L = count(str.begin(), str.end(), 'L');
		R = count(str.begin(), str.end(), 'R');
		U = count(str.begin(), str.end(), 'U');
		D = count(str.begin(), str.end(), 'D');
		L = R = min(L, R);
		U = D = min(U, D);
		if (L == 0) U = D = min(1, U);
		if (D == 0) L = R = min(1, L);
		cout << L + R + U + D << endl;
		while (L--) putchar('L');
		while (U--) putchar('U');
		while (R--) putchar('R');
		while (D--) putchar('D');
		puts("");

	}
	return 0;
}