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
const int N = 5e2 + 10;
char board[N][N];
stack<int> s;
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	MEM(board, ' ');
	string str;
	int sz;
	cin >> sz;
	cin >> str;
	int n = 0;
	for (int i = 0; i < sz; i++)
	{
		if (str[i] == '[')
		{
			s.push(i);
		}
		else
		{
			a[s.top()] = a[i] = s.size();
			n = max(n, int(s.size()));
			s.pop();
		}
	}
	int l = 0, r = 2 * (n + 1);
	int cur = 0;
	for (int i = 0; i < sz; i++)
	{
		if (str[i] == '[')
		{
			l++, r--;
			board[l][cur] = board[r][cur] = '+';
			board[l][cur + 1] = board[r][cur + 1] = '-';
			for (int i = l + 1; i < r; i++)
			{
				board[i][cur] = '|';
			}
		}
		else
		{
			if (str[i - 1] == '[') cur += 3;
			board[l][cur] = board[r][cur] = '+';
			board[l][cur - 1] = board[r][cur - 1] = '-';
			for (int i = l + 1; i < r; i++)
			{
				board[i][cur] = '|';
			}
			l--, r++;
		}
		cur++;
	}
	for (int i = l + 1; i < r; i++)
	{
		for (int j = 0; j < cur; j++) putchar(board[i][j]);
		puts("");
	}
	return 0;
}