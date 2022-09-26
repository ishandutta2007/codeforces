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

int n,k,ans;
int l[105];
int r[105];

int main()
{
	cin >> n;
	for (int i = 1;i <= n;i++)
		cin >> l[i] >> r[i];
	cin >> k;
	for (int i = 1;i <= n;i++)
		ans += r[i] >= k;
	cout << ans << endl;
	return 0;
}