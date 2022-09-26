#include <bits/stdc++.h>

using namespace std;

const int MAXN = 10005;

struct Triple
{
	int i,j,x;
};

int T,n;
int a[MAXN];

vector<Triple> ans;

void apply(int i,int j,int x)
{
	ans.push_back((Triple){i,j,x});
	a[i] -= i * x;
	if (a[i] < 0)
		assert(0);
	a[j] += i * x;
}

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		int sum = 0;
		for (int i = 1;i <= n;i++)
		{
			scanf("%d",&a[i]);
			sum += a[i];
		}
		if (sum % n != 0)
		{
			puts("-1");
			continue;
		}
		sum /= n;
		ans.clear();
		for (int i = 2;i <= n;i++)
		{
			apply(1,i,(i - (a[i] % i)) % i);
			apply(i,1,a[i] / i);
		}
		for (int i = 2;i <= n;i++)
			apply(1,i,sum);
		printf("%d\n",(int)ans.size());
		for (int i = 0;i < ans.size();i++)
			printf("%d %d %d\n",ans[i].i,ans[i].j,ans[i].x);
		for (int i = 1;i <= n;i++)
			if (a[i] != sum)
				while (1);
	}
	return 0;
}