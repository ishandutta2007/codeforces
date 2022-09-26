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

int a,b,c,l;

ll ans;

int main()
{
	scanf("%d%d%d%d",&a,&b,&c,&l);
	for (int i = 0;i <= l;i++)
	{
		int sum = a + b + c + i,up = (sum + 1) / 2;
		ans += (ll)(i + 2) * (i + 1) / 2;
		int low = max(up,a),high = sum - b - c;
		if (low <= high)
			ans -= (ll)(high - low + 1) * (i + a + 1) - (ll)(low + high) * (high - low + 1) / 2;
		low = max(up,b),high = sum - a - c;
		if (low <= high)
			ans -= (ll)(high - low + 1) * (i + b + 1) - (ll)(low + high) * (high - low + 1) / 2;
		low = max(up,c),high = sum - a - b;
		if (low <= high)
			ans -= (ll)(high - low + 1) * (i + c + 1) - (ll)(low + high) * (high - low + 1) / 2;
	}
	printf("%lld\n",ans);
	return 0;
}