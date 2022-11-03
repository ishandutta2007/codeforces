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
const int N = 2e2 + 10;
int s[N][N];
void init()
{
	char a = 'R', b = 'S', c = 'P';
	s[a][b] = 1;
	s[b][c] = 1;
	s[c][a] = 1;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	init();
	int n;
	cin >> n;
	string s1, s2;
	cin >> s1 >> s2;
	int l1 = s1.length(), l2 = s2.length();
	int r = n % (l1*l2);
	int d = n / (l1*l2);
	int a = 0, b = 0;
	for (int i = 0; i < l1*l2; i++)
	{
		char c1 = s1[i%l1];
		char c2 = s2[i%l2];
		a += s[c1][c2] * d;
		b += s[c2][c1] * d;
		if (i < r)
		{
			a += s[c1][c2];
			b += s[c2][c1];
		}
	}
	cout << b << ' ' << a << endl;
	
	return 0;
}