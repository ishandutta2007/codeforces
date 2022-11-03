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
		int d, k;
		scanf("%d%d", &d, &k);
		LL ptr = d;
		int flag = 1;
		for (int i = 0; i <= ptr; i++)
		{
			while ((1LL * i * i + 1LL * ptr * ptr) * k > 1LL * d * d ||
				(1LL * i * i + 1LL * ptr * ptr) * k * k > 1LL * d * d) ptr--;
			if (i > ptr) break;
			if (i == ptr)
			{
				flag = 0;
				break;
			}
		}
		if (flag) puts("Ashish");
		else puts("Utkarsh");
	}
	return 0;
}