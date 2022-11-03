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
#include <random>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e2 + 10;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	string heart = "<3";
	int n;
	string s1, s2;
	string str;
	s1 = heart;
	cin >> n;
	while (n--)
	{
		cin >> str;
		s1 += str + heart;
	}
	cin >> s2;
	int p = 0;
	for (int i = 0; i < s2.length(); i++)
	{
		if (p < s1.length() && s1[p] == s2[i]) p++;
	}
	if (p == s1.length()) puts("yes");
	else puts("no");
	return 0;
}