//by yjz
#include<bits/stdc++.h>
#define FF first
#define SS second
#define MP make_pair
#define PB push_back
typedef long long ll;
using namespace std;
int n, k;
map<int,int> mp;
int main()
{
	scanf("%d%d", &n, &k);
	int mx = 0;
	for (int i=1; i<=k+1; i++)
	{
		printf("?");
		for (int j=1; j<=k+1; j++)
		{
			if (i==j) continue;
			printf(" %d", j);
		}
		puts("");
		fflush(stdout);
		int p, v;
		scanf("%d%d", &p, &v);
		mp[v]++;
		mx = max(mx, v);
	}
	printf("! %d\n", mp[mx]);
	fflush(stdout);
	return 0;
}