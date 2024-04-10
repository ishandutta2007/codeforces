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

using namespace std;

int main()
{
	int y,b,r;
	cin >> y >> b >> r;
	b--;
	r -= 2;
	cout << 3 + min(y,min(b,r)) * 3 << endl;
	return 0;
}