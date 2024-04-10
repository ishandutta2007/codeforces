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
const int N = 2e5 + 10;
char s1[N], s2[N];
void refrain(char s[], int l, int r)
{
	if ((r - l) % 2 == 0) return;
	int mid = (l + r) / 2;
	refrain(s, l, mid);
	refrain(s, mid + 1, r);
	int flag = 0;
	int x = l;
	int y = mid + 1;
	while (x <= mid && y <= r)
	{
		if (s[x] == s[y])
		{
			x++, y++;
			continue;
		}
		if (s[x] > s[y])
		{
			flag = 1;
		}
		break;
	}
	x = l, y = mid + 1;
	if (flag)
	{
		while (x <= mid && y <= r)
		{
			swap(s[x++], s[y++]);
		}
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%s%s", s1, s2);
	int n = strlen(s1);
	refrain(s1, 0, n - 1);
	refrain(s2, 0, n - 1);
	if (strcmp(s1, s2) == 0) puts("YES");
	else puts("NO");
	return 0;
}