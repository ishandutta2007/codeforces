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

int n,q,cnt,MAX;
int head,tail;
int Q[MAXN << 1];

pair<int,int> ans[MAXN];

int main()
{
	scanf("%d%d",&n,&q);
	head = 1;
	for (int a,i = 1;i <= n;i++)
	{
		scanf("%d",&a);
		Q[++tail] = a;
		MAX = max(MAX,a);
	}
	while (Q[head] != MAX)
	{
		int A = Q[head++];
		int B = Q[head++];
		if (A >= B)
		{
			Q[--head] = A;
			Q[++tail] = B;
		}
		else
		{
			Q[--head] = B;
			Q[++tail] = A;
		}
		ans[++cnt] = make_pair(A,B);
	}
	while (q--)
	{
		long long t;
		cin >> t;
		if (t <= cnt)
		{
			printf("%d %d\n",ans[t].first,ans[t].second);
			continue;
		}
		t -= cnt;
		printf("%d %d\n",Q[head],Q[(t - 1) % (n - 1) + 1 + head]);
	}
	return 0;
}