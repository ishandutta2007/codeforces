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
const int N = 2e5 + 20;
int pos[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int L = 0, R = 0;
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		char op;
		int id;
		scanf(" %c%d", &op, &id);
		if (op == 'L')
		{
			pos[id] = --L;
		}
		else if (op == 'R')
		{
			pos[id] = ++R;
		}
		else
		{
			if (pos[id] < 0)
			{
				printf("%d\n", min(pos[id] - L, R - pos[id] - 1));
			}
			else
			{
				printf("%d\n", min(R - pos[id], pos[id] - L - 1));
			}
		}
	}
	return 0;
}