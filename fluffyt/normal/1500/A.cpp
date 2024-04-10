#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
 
const int MAXN = 200005;
int a[MAXN], n;
vector<pair<int, int> > vec[5000005];
vector<int> ppp[2500005];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", a + i);
		ppp[a[i]].push_back(i);
		if ((int)ppp[a[i]].size() >= 4)
			return printf("YES\n%d %d %d %d\n", ppp[a[i]][0], ppp[a[i]][1], ppp[a[i]][2], ppp[a[i]][3]), 0;
	}
	for (int i = 1; i <= n; i++)
	for (int j = i + 1; j <= n; j++) {
		int s = a[i] + a[j];
		for (auto &k : vec[s]) {
			if (k.first != i && k.second != i && k.second != j && k.first != j)
				return printf("YES\n%d %d %d %d\n", i, j, k.first, k.second), 0;
		}
		vec[s].push_back(make_pair(i, j));
	}
	puts("NO");
	return 0;
}