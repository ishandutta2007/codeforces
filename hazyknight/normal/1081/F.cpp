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
#include <assert.h>

using namespace std;

int n,t;
int a[305];
int ans[305];

int ask(int l,int r)
{
	cout << "? " << l << ' ' << r << endl;
	cout.flush();
	int res = 0;
	cin >> res;
	return res;
}

int flip(int r)
{
	int last = 0;
	if ((n & 1) != (r & 1))
	{
		bool cnt0 = 0,cnt1 = 0;
		last = t;
		while (!cnt0 || cnt1)
		{
			int res = ask(1,r);
			if (((res - last) & 1) == (r & 1))
				cnt0 ^= 1;
			else
				cnt1 ^= 1;
			last = res;
		}
	}
	else
	{
		if (r == 1)
		{
			last = ask(1,n);
			bool cnt0 = 0,cnt1 = 0;
			while (cnt0 || !cnt1)
			{
				int res = ask(2,n);
				if (((res - last) & 1) == (n & 1))
					cnt0 ^= 1;
				else
					cnt1 ^= 1;
				last = res;
			}
		}
		else
		{
			bool cnt0 = 0,cnt1 = 0;
			last = t;
			while (!cnt0 || cnt1)
			{
				int res = ask(2,r);
				if (((res - last) & 1) == (r & 1))
					cnt0 ^= 1;
				else
					cnt1 ^= 1;
				last = res;
			}
		}
	}
	return last;
}

int main()
{
	cin >> n >> t;
	if (n == 1)
	{
		cout << "! " << t << endl;
		return 0;
	}
	int last = t;
	for (int i = 1;i <= n;i++)
	{
		t = flip(i);
		if (t < last)
			ans[i] = 1;
		last = t;
		t = flip(i);
	}
	cout << "! ";
	for (int i = 1;i <= n;i++)
		cout << ans[i];
	cout << endl;
	return 0;
}