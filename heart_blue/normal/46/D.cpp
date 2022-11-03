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
const int N = 3e5 + 10;
int flag[N];
int pos[N];
int len[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int offset = 1e5;
	int l, b, f;
	cin >> l >> b >> f;
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int op, x;
		scanf("%d%d", &op, &x);
		if (op == 2)
		{
			for (int j = 0; j < len[x]; j++)
			{
				flag[pos[x] + j] = 0;
			}
			pos[x] = 0;
		}
		else
		{
			int sum = 0;
			for (int j = 1; j <= l + f; j++)
			{
				sum += flag[j + offset];
				if (j >= x + f)
				{
					sum -= flag[j + offset - x - b - f];
					if (sum == 0)
					{
						int id = j - x - f + 1 + offset;
						for (int j = 0; j < x; j++)
							flag[id + j] = 1;
						pos[i] = id;
						break;
					}
				}
			}
			len[i] = x;
			if (pos[i]) printf("%d\n", pos[i] - offset - 1);
			else puts("-1");
		}
	}
	return 0;
}