#include <cstdio>
#include <vector>
const int N = 2000;
int n, a[N];
bool chk[N];
std::vector<int> ans;

int mex()
{
	for (int i = 0; i < n; ++i)
		chk[i] = false;
	for (int i = 0; i < n; ++i)
		chk[a[i]] = true;
	for (int i = 0; i < n; ++i)
		if (!chk[i])
			return i;
	return n;
}

bool edit(int mx)
{
	if (mx == n)
		return false;
	ans.push_back(mx);
	a[mx] = mx;
	return true;
}

void update()
{
	while (edit(mex()));
}

int main()
{
	int t; scanf("%d", &t);
	for (int i = 0; i < t; ++i)
	{
		scanf("%d", &n);
		for (int i = 0; i < n; ++i)
			scanf("%d", &a[i]);
		ans.clear();
		update();
		for (int i = 0; i < n; ++i)
			if (a[i] != i)
			{
				ans.push_back(i);
				a[i] = n;
				update();
			}
		printf("%d\n", ans.size());
		for (int x : ans)
			printf("%d ", x + 1);
		printf("\n");
	}
}