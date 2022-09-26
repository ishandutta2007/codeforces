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
#include <fstream>
#include <bitset>

using namespace std;

int n;

vector<pair<int,int> > ans;

void gg()
{
	cout << "! " << ans[0].first << ' ' << ans[0].second << ' ' << ans[1].first << ' ' << ans[1].second << endl;
	cout.flush();
	exit(0);
}

bool ask(int xa,int ya,int xb,int yb)
{
	cout << "? " << xa << ' ' << ya << ' ' << xb << ' ' << yb << endl;
	cout.flush();
	int res;
	cin >> res;
	return res & 1;
}

void work1(int y)
{
	int low = 1,high = n;
	while (low < high)
	{
		int mid = (low + high) >> 1;
		if (ask(low,y,mid,y))
			high = mid;
		else
			low = mid + 1;
	}
	ans.push_back(make_pair(low,y));
	if (ans.size() == 2)
		gg();
}

void work2(int x)
{
	int low = 1,high = n;
	while (low < high)
	{
		int mid = (low + high) >> 1;
		if (ask(x,low,x,mid))
			high = mid;
		else
			low = mid + 1;
	}
	ans.push_back(make_pair(x,low));
	if (ans.size() == 2)
		gg();
}

int main()
{
	cin >> n;
	for (int i = 1;i < n;i++)
		if (ask(1,i,n,i))
			work1(i);
	if (ans.size() == 1)
		work1(n);
	for (int i = 1;i < n;i++)
		if (ask(i,1,i,n))
			work2(i);
	if (ans.size() == 1)
		work2(n);
	return 0;
}