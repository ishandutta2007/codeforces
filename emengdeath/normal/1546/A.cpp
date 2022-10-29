#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;
int a[101];
int b[101];
int main() {
	int T;
	scanf("%d", &T);
	while (T --) {
		int n;
		scanf("%d", &n);
		int all = 0;
		for (int i = 1; i <= n;i ++) {
			scanf("%d", &a[i]);
			all += a[i];
		}
		for (int i = 1; i <= n;i ++) {
			scanf("%d", &b[i]);
			all -= b[i];
		}
		if (all) {
			puts("-1");
			continue;
		}
		vector<pair<int, int> > ans;
		for (int i = 1; i <= n; i ++) 
		{	
			while (a[i] > b[i]) {
				for (int j = 1; j <= n; j ++)
					if (a[j] < b[j]) {
						a[j] ++, a[i] --, ans.push_back({i, j});
						break;
					}
			}
		}
		printf("%d\n", ans.size());
		for (auto u:ans)
			printf("%d %d\n", u.first, u.second);
	}
	return 0;
}