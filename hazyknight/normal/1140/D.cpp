#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <assert.h>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <stack>
#include <queue>
#include <map>
#include <set>

using namespace std;

int n,ans;

int main()
{
	cin >> n;
	for (int i = 2;i < n;i++)
		ans += i * (i + 1);
	cout << ans << endl;
	return 0;
}