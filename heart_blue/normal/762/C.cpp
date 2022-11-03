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
int L[N];
int R[N];
char s1[N];
char s2[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%s%s", s1 + 1, s2 + 1);
	int n = strlen(s1 + 1);
	int m = strlen(s2 + 1);
	int ptr = 1;
	for (int i = 1; i <= m; i++)
	{
		while (ptr <= n && s1[ptr] != s2[i])
		{
			L[ptr] = L[ptr - 1];
			ptr++;
		}
		if (s1[ptr] == s2[i])
		{
			L[ptr++] = i;
		}
	}
	while (ptr <= n)
	{
		L[ptr] = L[ptr - 1];
		ptr++;
	}
	ptr = n;
	for (int i = m; i > 0; i--)
	{
		while (ptr > 0 && s1[ptr] != s2[i])
		{
			R[ptr] = R[ptr + 1];
			ptr--;
		}
		if (s1[ptr] == s2[i])
		{
			R[ptr--] = i;
		}
	}
	while (ptr > 0)
	{
		R[ptr] = R[ptr + 1];
		ptr--;
	}
	if (L[n] == m)
	{
		puts(s2 + 1);
		return 0;
	}
	if (L[n] == 0 && R[1] == 0)
	{
		puts("-");
		return 0;
	}
	tuple<int, int, int> ans = max(
		make_tuple(R[1] > 0 ? m - R[1] + 1 : 0, 0, R[1]),
		make_tuple(L[n], L[n], m + 1));
	for (int i = 1; i < n; i++)
	{
		if (R[i + 1] != 0)
			ans = max(ans, make_tuple(L[i] + m - R[i + 1] + 1, L[i], R[i]));
	}
	int tot, l, r;
	tie(tot, l, r) = ans;
	if (tot == m) l = 1, r = 2;
	for (int i = 1; i <= l; i++) putchar(s2[i]);
	for (int j = r; j <= m; j++) putchar(s2[j]);
	return 0;
}