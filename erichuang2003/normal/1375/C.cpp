#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 300005;

int T,n,tot;
int a[MAXN];

vector<int> v[MAXN];

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		for (int i = 1;i <= n;i++)
			scanf("%d",&a[i]);
		puts(a[1] < a[n] ? "YES" : "NO");
	}
	return 0;
}