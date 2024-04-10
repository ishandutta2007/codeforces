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

const int MAXN = 100005;

int n,a,b;
int v[MAXN];

ll ans;

int main()
{
	scanf("%d",&n);
	for (int i = 1;i <= n;i++)
	{
		scanf("%d%d",&a,&b);
		ans += (ll)n * b - a;
		v[i] = a - b;
	}
	sort(v + 1,v + n + 1);
	for (int i = 1;i <= n;i++)
		ans += (ll)v[i] * (n - i + 1);
	printf("%I64d\n",ans);
	return 0;
}