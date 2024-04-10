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
#include <set>
#include <iomanip>

using namespace std;

const int MAXN = 100005;

int n,A,B; 
int a[MAXN];
int b[MAXN];

string s,ans;

void go(int t)
{
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	A = B = 0;
	for (int i = t;i >= 0;i--)
		a[A++] = s[i] - '0';
	for (int i = s.size() - 1;i >= t + 1;i--)
		b[B++] = s[i] - '0';
	for (int i = 0;i < max(A,B);i++)
	{
		a[i] += b[i];
		a[i + 1] += a[i] / 10;
		a[i] %= 10;
	}
	int len = 0;
	if (a[max(A,B)])
		len = max(A,B) + 1;
	else
		len = max(A,B);
	string cur;
	cur.resize(len);
	for (int i = len - 1;i >= 0;i--)
		cur[i] = a[i] + '0';
	reverse(cur.begin(),cur.end());
	if (ans == "" || (ans.size() > cur.size() || (ans.size() == cur.size() && ans > cur)))
		ans = cur;
}

int main()
{
	ios::sync_with_stdio(0);
	cin >> n >> s;
	int cnt = 0;
	int half = (n - 1) >> 1;
	for (int i = half;i >= 0;i--)
		if (s[i + 1] != '0')
		{
			go(i);
			cnt++;
			if (cnt > 1)
				break;
		}
	cnt = 0;
	for (int i = half;i + 1 < s.size();i++)
		if (s[i + 1] != '0')
		{
			go(i);
			cnt++;
			if (cnt > 1)
				break;
		}
	cout << ans << endl;
	return 0;
}