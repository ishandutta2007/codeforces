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
const LL INF = 1e9 + 7;
const int N = 5e2 + 10;
vector<string> vs;
vector<string> vs2;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	string s1, s2;
	cin >> s1 >> s2;
	reverse(s1.begin(), s1.end());
	reverse(s2.begin(), s2.end());
	int l1 = s1.length();
	int l2 = s2.length();
	int n = max(l1, l2);
	s1 += string(n - l1, '0');
	s2 += string(n - l2, '0');
	char c = '=';
	for (int i = n - 1; i >= 0; i--)
	{
		if (s1[i] == s2[i]) continue;
		if (s1[i] > s2[i]) c = '>';
		else c = '<';
		break;
	}
	putchar(c);
	
	return 0;
}