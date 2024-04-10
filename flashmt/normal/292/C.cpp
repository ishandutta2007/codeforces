#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <utility>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <sstream>
using namespace std;

int n, mustHave, mask[256], a[20], b[10];
set <string> ans;

int getMask(int n)
{
	if (n < 10) return 1 << n;
	return 1 << (n % 10) | getMask(n / 10);
}

void work(int i, int cur, int len, string s)
{
	if (cur == 4)
	{
		if (i != len) return;
		ans.insert(s); 
	}
	else
	{
		string t = "";
		if (cur) t = ".";
		for (int j = 0, x = 0; j < 3 && i + j < len; j++)
		{
			x = x * 10 + a[i + j];
			t += char('0' + a[i + j]);
			if (!j || a[i]) 
			{
				if (x > 255) continue;
				b[cur] = x;
				work(i + j + 1, cur + 1, len, s + t);
			}
		}
	}
}

void att(int i, int len, int have)
{
	if (i > len - 1 - i)
	{
		if (have != mustHave) return;
		work(0, 0, len, "");
	}
	else
		for (int j = 0; j < 10; j++)
			if (mustHave >> j & 1) 
			{
				a[i] = a[len - 1 - i] = j;
				att(i + 1, len, have | 1 << j);
			}
}

int main()
{
	int x;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> x, mustHave |= 1 << x;
	for (int i = 0; i < 256; i++) mask[i] = getMask(i);
	for (int len = 4; len <= 12; len++) att(0, len, 0);
	
	cout << ans.size() << endl;
	for (set <string>::iterator it = ans.begin(); it != ans.end(); it++) cout << *it << endl;
}