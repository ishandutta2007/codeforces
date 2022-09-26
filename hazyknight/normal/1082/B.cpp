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

const int MAXN = 100005;

int n,ans,SUM;
int pre[MAXN];
int nxt[MAXN];

string s;

int main()
{
	cin >> n >> s;
	for (int i = 0;i < s.size();i++)
		SUM += (s[i] == 'G');
	for (int i = 1;i <= n;i++)
	{
		if (s[i - 1] == 'S')
			pre[i] = 0;
		else
			pre[i] = pre[i - 1] + 1;
		ans = max(ans,pre[i]);
	}
	for (int i = n;i >= 1;i--)
	{
		if (s[i - 1] == 'S')
			nxt[i] = 0;
		else
			nxt[i] = nxt[i + 1] + 1;
		ans = max(ans,nxt[i]);
	}
	for (int i = 1;i <= n;i++)
		ans = max(ans,pre[i - 1] + nxt[i + 1] + 1);
	cout << min(ans,SUM) << endl;
	return 0;
}