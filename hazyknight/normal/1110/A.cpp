#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <iomanip>
#include <fstream>

using namespace std;

int b,k,sum;
int a[100005];

int main()
{
	ios::sync_with_stdio(false);
	cin >> b >> k;
	for (int i = 1;i <= k;i++)
	{
		cin >> a[i];
		sum += a[i];
	}
	if (b & 1)
	{
		if (sum & 1)
			cout << "odd" << endl;
		else
			cout << "even" << endl;
	}
	else
	{
		if (a[k] & 1)
			cout << "odd" << endl;
		else
			cout << "even" << endl;
	}
	return 0;
}