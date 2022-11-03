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
const int N = 1e2 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	string key = "RRRRPSSPRR", st, s, t;
	for (int i = 0; i < 10; i++)
	{
		cout << key[i] << endl;
		getline(cin, st);
		s += st == "ai" ? '0' : '1';
	}
	if (s == "0000100100")	t = "PPPPPPPPPP";
	if (s == "0000011000")	t = "SSSSSSSSSS";
	if (s == "1111000011")	t = "RRRRRRRRRR";
	if (s == "0010000010")	t = "SRPSRPSRPS";
	if (s == "0000110000")	t = "PSRPSRPSRP";
	if (s == "0000000110")	t = "SPRSPRSPRS";
	for (int i = 0; i < 10; i++)
	{
		cout << t[i] << endl;
		getline(cin, st);
	}
	return 0;
}