#include <bits/stdc++.h>

using namespace std;

const int MAXN = 55;

int T,n;
int a[MAXN];

set<int> S;

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		for (int i = 1;i <= n;i++)
			scanf("%d",&a[i]);
		S.clear();
		for (int i = 1;i <= n;i++)
			for (int j = i + 1;j <= n;j++)
				S.insert(a[j] - a[i]);
		printf("%d\n",(int)S.size());
	}
	return 0;
}