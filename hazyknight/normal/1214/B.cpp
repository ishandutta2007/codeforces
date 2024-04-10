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

int b,g,n,ans;

int main()
{
	cin >> b >> g >> n;
	for (int i = 0;i <= min(n,b);i++)
		if (n - i <= g)
			ans++;
	cout << ans << endl;
	return 0;
}