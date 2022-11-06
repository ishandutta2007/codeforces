#include <map>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef pair <int, int> Pii;
#define N 500000 + 5
#define mp make_pair

int n, ans;
char s[N];
map <Pii, int> Map;

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++)
	{
		scanf("%s", s);
		int sum = 0, mn = 0;
		for (int j = 0; s[j]; j ++)
		{
			int cur = s[j] == '(' ? 1 : -1;
			sum += cur;
			mn = min(sum, mn);
		}
		if (sum >= 0 && mn == 0)
		{
			if (Map[mp(-sum, -sum)] > 0)
				Map[mp(-sum, -sum)] --, ans ++;
			else Map[mp(sum, mn)] ++;
		}
		else if (sum < 0 && sum == mn)
		{
			if (Map[mp(-sum, 0)] > 0)
				Map[mp(-sum, 0)] --, ans ++;
			else Map[mp(sum, mn)] ++;
		}
	}
	printf("%d\n", ans);
	
	return 0;
}