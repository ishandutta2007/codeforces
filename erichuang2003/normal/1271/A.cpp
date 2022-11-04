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

int a,b,c,d,e,f,ans;

int main()
{
	cin >> a >> b >> c >> d >> e >> f;
	b = min(b,c);
	for (int i = 0;i <= d;i++)
		ans = max(ans,min(a,i) * e + min(b,d - i) * f);
	printf("%d\n",ans);
	return 0;
}