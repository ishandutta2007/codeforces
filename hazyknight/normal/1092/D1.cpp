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

int n;
int a[200005];

stack<int> S;

int main()
{
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
		a[i] &= 1;
	}
	for (int i = 1;i <= n;i++)
	{
		if (S.empty() || S.top() != a[i])
			S.push(a[i]);
		else
			S.pop();
	}
	cout << (S.size() <= 1 ? "YES" : "NO") << endl;
	return 0;
}