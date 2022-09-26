#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <bitset>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>

using namespace std;

const int MAXN = 300005;

int n,tota,totb;

pair<int,int> A[MAXN];
pair<int,int> B[MAXN];

int main()
{
	scanf("%d",&n);
	for (int a,b,i = 1;i <= n;i++)
	{
		scanf("%d%d",&a,&b);
		if (a < b)
			A[++tota] = make_pair(a,i);
		if (a > b)
			B[++totb] = make_pair(a,i);
	}
	if (tota > totb)
	{
		sort(A + 1,A + tota + 1);
		reverse(A + 1,A + tota + 1);
		printf("%d\n",tota);
		for (int i = 1;i <= tota;i++)
			printf("%d ",A[i].second);
		printf("\n");
		return 0;
	}
	sort(B + 1,B + totb + 1);
	printf("%d\n",totb);
	for (int i = 1;i <= totb;i++)
		printf("%d ",B[i].second);
	printf("\n");
	return 0;
}