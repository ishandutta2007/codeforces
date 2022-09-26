#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <vector>
#include <bitset>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

int n,a;

int main()
{
	cin >> n;
	int sum = 0;
	for (int i = 1;i <= n;i++)
	{
		cin >> a;
		if (a % 2 == 0)
		{
			cout << a / 2 << endl;
			continue;
		}
		if (sum < 0)
		{
			cout << (a + 1) / 2 << endl;
			sum++;
		}
		else
		{
			cout << (a - 1) / 2 << endl;
			sum--;
		}
	}
	return 0;
}