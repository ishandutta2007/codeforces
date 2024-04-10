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

int n,m;

int main()
{
	cin >> n >> m;
	int cnt = 0;
	while (n > 0)
	{
		cnt++;
		if (n <= 5)
			break;
		n -= 4;
	}
	for (int i = 1;i < cnt;i++)
		cout << 4;
	cout << 5 << endl;
	for (int i = 1;i <= cnt;i++)
		cout << 5;
	cout << endl;
	return 0;
}