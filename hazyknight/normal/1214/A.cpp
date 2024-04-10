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

int n,d,e,ans;

int main()
{
	cin >> n >> d >> e;
	ans = n;
	for (int i = 0;i * e <= n;i += 5)
		ans = min(ans,(n - i * e) % d);
	cout << ans << endl;
	return 0;
}