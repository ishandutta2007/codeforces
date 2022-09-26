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
const int INF = (1 << 30) - 1;

int n,q,top,l,r;
int a[MAXN];
int S[MAXN];

long long ans;

int main()
{
	scanf("%d%d",&n,&q);
	for (int i = 1;i <= n;i++)
		scanf("%d",&a[i]);
	for (int i = 1;i < n;i++)
		a[i] = abs(a[i + 1] - a[i]);
	n--;
	while (q--)
	{
		cin >> l >> r;
		r--;
		S[top = 1] = l - 1;
		int tmpl = a[l - 1],tmpr = a[r + 1];
		a[l - 1] = INF + 1;
		a[r + 1] = INF;
		ans = 0;
		for (int i = l;i <= r + 1;i++)
		{
			while (a[S[top]] <= a[i])
			{
				ans += (long long)a[S[top]] * (S[top] - S[top - 1]) * (i - S[top]);
				top--;
			}
			S[++top] = i;
		}
		a[l - 1] = tmpl;
		a[r + 1] = tmpr;
		cout << ans << endl;
	}
	return 0;
}