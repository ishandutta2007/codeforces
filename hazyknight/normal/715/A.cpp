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

typedef long long ll;

ll n;

int main()
{
	cin >> n;
	ll cur = 2;
	for (ll i = 1;i <= n;i++)
	{
		ll a = i * (i + 1) * (i + 1);
		printf("%lld\n",a - cur);
		cur = i;
	}
	return 0;
}