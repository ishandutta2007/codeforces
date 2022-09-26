#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <assert.h>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <stack>
#include <map>
#include <set>

using namespace std;

int n,x,y;

vector<char> ans1,ans2;

bool ok(int r1,int c1,int r2,int c2)
{
	cout << "? " << r1 << ' ' << c1 << ' ' << r2 << ' ' << c2 << endl;
	fflush(stdout);
	string res;
	cin >> res;
	assert(res != "BAD");
	if (res == "YES")
		return true;
	return false;
}

int main()
{
	cin >> n;
	x = 1,y = 1;
	while (n - x + n - y > n - 1)
	{
		if (ok(x + 1,y,n,n))
		{
			ans1.push_back('D');
			x++;
		}
		else
		{
			ans1.push_back('R');
			y++;
		}
	}
	x = n,y = n;
	while (x - 1 + y - 1 > n - 1)
	{
		if (ok(1,1,x,y - 1))
		{
			ans2.push_back('R');
			y--;
		}
		else
		{
			ans2.push_back('D');
			x--;
		}
	}
	cout << "! ";
	for (int i = 0;i < ans1.size();i++)
		cout << ans1[i];
	for (int i = ans2.size() - 1;i >= 0;i--)
		cout << ans2[i];
	cout << endl;
	fflush(stdout);
	return 0;
}