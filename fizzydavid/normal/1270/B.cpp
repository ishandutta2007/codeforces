//by yjz
#include<bits/stdc++.h>
#define FF first
#define SS second
#define MP make_pair
#define PB push_back
typedef long long ll;
using namespace std;
int tn, n;
int a[200111];
int main()
{
	scanf("%d", &tn);
	while (tn--)
	{
		scanf("%d", &n);
		for (int i=1; i<=n; i++)
		{
			scanf("%d", &a[i]);
		}
		int l = -1;
		for (int i=1; i<n; i++)
		{
			if (abs(a[i]-a[i+1])>1) l = i;
		}
		if (l==-1) puts("NO");
		else
		{
			puts("YES");
			printf("%d %d\n", l, l+1);
		}
	}
	return 0;
}