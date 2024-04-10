#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <vector>
#include <bitset>
#include <stack>
#include <queue>
#include <set>
#include <map>

using namespace std;

int n,a,MIN,cnt;

int main()
{
	MIN = 51;
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		cin >> a;
		if (a < MIN)
		{
			MIN = a;
			cnt = 1;
		}
		else if (a == MIN)
			cnt++;
	}
	cout << (cnt > n / 2 ? "Bob" : "Alice") << endl;
	return 0;
}