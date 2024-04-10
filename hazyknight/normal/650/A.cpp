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

int n;

long long ans;

map<int,int> cntx,cnty;
map<pair<int,int>,int> cnt;

int main()
{
	scanf("%d",&n);
	for (int x,y,i = 1;i <= n;i++)
	{
		scanf("%d%d",&x,&y);
		ans -= cnt[make_pair(x,y)]++;
		ans += cntx[x]++;
		ans += cnty[y]++;
	}
	printf("%lld\n",ans);
	return 0;
}