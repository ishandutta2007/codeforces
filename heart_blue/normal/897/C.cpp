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
string f0 = "What are you doing at the end of the world? Are you busy? Will you save us?";
string pre = "What are you doing while sending \"";
string mid = "\"? Are you busy? Will you send \"";
string aft = "\"?";
const LL inf = 2 * INF*INF;
LL len[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	len[0] = f0.length();
	for (int i = 1; i < N; i++)
	{
		if (len[i - 1] > inf) len[i] = LLONG_MAX;
		else len[i] = pre.length() + len[i - 1] * 2 + mid.length() + aft.length();
	}
	cin >> ncase;
	while (ncase--)
	{
		int n;
		LL k;
		cin >> n >> k;
		// fi+1 = pre + fi + mid + fi + aft;
		if (k > len[n])
		{
			cout << '.';
			continue;
		}
		if (n == 0)
		{
			cout << f0[k - 1];
		}
		while (n)
		{
			if (k <= pre.length())
			{
				cout << pre[k - 1];
				goto layer;
			}
			if (k - pre.length() <= len[n - 1])
			{
				k -= pre.length();
				n--;
				if (n == 0)
				{
					cout << f0[k - 1];
					goto layer;
				}
				continue;
			}
			if (k <= pre.length() + len[n - 1] + mid.length())
			{
				cout << mid[k - pre.length() - len[n - 1] - 1];
				goto layer;
			}
			if (len[n - 1] == LLONG_MAX)
			{
				n--;
				if (n == 0)
				{
					cout << f0[k - 1];
					goto layer;
				}
				continue;
			}
			if (k <= pre.length() + len[n - 1] * 2 + mid.length())
			{
				k -= pre.length() + len[n - 1] + mid.length();
				n--;
				if (n == 0)
				{
					cout << f0[k - 1];
					goto layer;
				}
				continue;
			}
			k -= pre.length() + 2 * len[n - 1] + mid.length();
			cout << aft[k - 1];
			break;
		}
	layer:
		;
	}
	return 0;
}