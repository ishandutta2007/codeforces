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

typedef long long ll;

const int MOD = 998244353;

int w,h,ans;

int main()
{
	cin >> w >> h;
	ans = 1;
	for (int i = 1;i <= w + h;i++)
		(ans <<= 1) %= MOD;
	cout << ans << endl;
	return 0;
}