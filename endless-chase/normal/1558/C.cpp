#include <bits/stdc++.h>
#define Accepted 0
using namespace std;
int test, n, p[2222], a, b;
vector<int> ans;
bool flg;
void rev(int x)
{
	ans.push_back(x);
	for (int i = 1; i <= x / 2; i++) swap(p[i], p[x + 1 - i]);
}
int main()
{
	scanf("%d", &test);
	while(test--)
	{
		scanf("%d", &n);
		ans.clear();
		for (int i = 1; i <= n; i++) scanf("%d", &p[i]);
		flg = 0;
		for (int i = 1; i <= n; i++)
		{
			if ((i & 1) && !(p[i] & 1)) flg = 1;
			if (!(i & 1) && (p[i] & 1)) flg = 1;
		}
		if (flg)
		{
			printf("-1\n");
			continue;
		}
		for (int i = n; i > 1; i -= 2)
		{
			for (int j = 1; j <= i; j++)
			{
				if (p[j] == i) a = j;
				if (p[j] == i - 1) b = j;
			}
			if (a > 1)
			{
				rev(a);
				if (b <= a) b = a + 1 - b;
				a = 1;
			}
			if (b == 2)
			{
				rev(i);
			}
			else
			{
				rev(b - 1);
				a = b - 1;
				rev(b + 1);
				b = 2; a = 3;
				rev(3);
				rev(i);
			}
		}
		printf("%d\n", (int)ans.size());
		for (int i = 0; i < ans.size(); i++) printf("%d ", ans[i]);
		printf("\n");
	//	for (int i = 1; i <= n; i++) printf("%d ", p[i]);
	//	printf("\n");
	}
	return Accepted;
}