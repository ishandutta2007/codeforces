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
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	string str;
	cin >> n;
	cin >> str;
	for (int i = 'a'; i <= 'z'; i++)
	{
		int x = str.find_first_of(i);
		if (x == str.npos) continue;
		for (int j = 'a'; j < i; j++)
		{
			int y = str.find_last_of(j);
			if (y == str.npos) continue;
			if (x < y)
			{
				puts("YES");
				printf("%d %d\n", x + 1, y + 1);
				return 0;
			}
		}
	}
	puts("NO");
	return 0;
}