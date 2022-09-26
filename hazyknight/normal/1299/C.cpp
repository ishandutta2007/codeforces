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
typedef double db;

const int MAXN = 1000005;

int n,top;

pair<ll,int> S[MAXN];

int main()
{
	scanf("%d",&n);
	for (int a,i = 1;i <= n;i++)
	{
		scanf("%d",&a);
		pair<ll,int> cur = make_pair(a,1);
		while (top > 0 && S[top].first * cur.second > cur.first * S[top].second)
		{
			cur.first += S[top].first;
			cur.second += S[top].second;
			top--;
		}
		S[++top] = cur;
	}
	for (int i = 1;i <= top;i++)
		for (int j = 1;j <= S[i].second;j++)
			printf("%.10lf\n",(db)S[i].first / S[i].second);
	return 0;
}