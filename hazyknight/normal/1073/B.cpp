#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <iomanip>

using namespace std;

int n;
int a[200005];
int b;

stack<int> S;

bool mark[200005];

int main()
{
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1;i <= n;i++)
		cin >> a[i];
	for (int i = n;i >= 1;i--)
		S.push(a[i]),mark[a[i]] = true;
	for (int i = 1;i <= n;i++)
	{
		cin >> b;
		if (!mark[b])
			cout << 0 << ' ';
		else
		{
			int ans = 0;
			while (S.top() != b)
			{
				mark[S.top()] = false;
				S.pop();
				ans++;
			}
			mark[b] = false;
			S.pop();
			ans++;
			cout << ans << ' ';
		}
	}
	cout << endl;
	return 0;
}