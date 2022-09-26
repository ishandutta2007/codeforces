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

int T,n,t;

int main()
{
	cin >> T;
	while (T--)
	{
		cin >> n >> t;
		for (int i = 1;i <= n;i++)
			cout << char((i - 1) % t + 'a');
		cout << endl;
	}
	return 0;
}