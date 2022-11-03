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
	LL n;
	LL cnt[10];
	cin >> n;
	for (int i = 1; i <= 8; i++) cin >> cnt[i];
	LL ans = 0;
	for (int i1 = 0; i1 < 10; i1++)
	{
		for (int i2 = 0; i2 < 10; i2++)
		{
			for (int i3 = 0; i3 < 10; i3++)
			{
				for (int i4 = 0; i4 < 10; i4++)
				{
					for (int i5 = 0; i5 < 10; i5++)
					{
						for (int i6 = 0; i6 < 10; i6++)
						{
							for (int i7 = 0; i7 < 10; i7++)
							{
								int a[10] = { 0,i1,i2,i3,i4,i5,i6,i7 };
								LL b[10];
								int flag = 0;
								LL rest = n;
								for (int i = 1; i <= 7; i++)
								{
									b[i] = min(cnt[i], rest / i);
									rest -= b[i] * i;
									if (b[i] < a[i])
									{
										flag = 1;
										break;
									}
									rest += a[i] * i;
								}
								if (flag) continue;
								LL o = min(cnt[8], rest / 8);
								rest -= o * 8;
								ans = max(ans, n - rest);
							}
						}
					}
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}