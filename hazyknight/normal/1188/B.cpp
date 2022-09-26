#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <bitset>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>

using namespace std;

typedef long long ll;

int n;

ll p,k,ans;

map<ll,ll> cnt;

int main()
{
	scanf("%d%lld%lld",&n,&p,&k);
	for (int i = 1;i <= n;i++)
	{
		ll a;
		scanf("%lld",&a);
		cnt[(a * a % p * a % p * a % p - k * a % p + p) % p]++;
	}
	for (map<ll,ll>::iterator i = cnt.begin();i != cnt.end();i++)
		ans += i->second * (i->second - 1) / 2;
	printf("%lld\n",ans);
	return 0;
}