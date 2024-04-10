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

int T,n,s,t;

int main()
{
	cin >> T;
	while (T--)
	{
		cin >> n >> s >> t;
		int b = s + t - n,a = s - b,c = t - b;
		cout << max(a,c) + 1 << endl;
	}
	return 0;
}