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

const int MAXN = 100005;

int a,b,c,n,ans;
int x[MAXN];

int main()
{
	scanf("%d%d%d%d",&a,&b,&c,&n);
	for (int i = 1;i <= n;i++)
		scanf("%d",&x[i]);
	sort(x + 1,x + n + 1);
	for (int i = 1;i <= n;i++)
		if (x[i] > b && x[i] < c)
			ans++;
	printf("%d\n",ans);
	return 0;
}