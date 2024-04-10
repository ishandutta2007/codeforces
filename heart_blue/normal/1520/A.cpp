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
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		scanf("%*d");
		string str;
		cin >> str;
		int ok = 1;
		for (int i = 'A'; i <= 'Z'; i++)
		{
			int l = str.find_first_of(i);
			int r = str.find_last_of(i);
			if (l == str.npos) continue;
			if (count(str.begin(), str.end(), i) != r - l + 1)
			{
				ok = 0;
				break;
			}
		}
		if (ok) puts("YES");
		else puts("NO");
	}
	return 0;
}