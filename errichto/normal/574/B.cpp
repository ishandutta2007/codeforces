#include<bits/stdc++.h>
using namespace std;

const int inf = 100000005;
const int nax = 5005;
int degree[nax];
bool t[nax][nax];

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 0; i < m; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		t[a][b] = t[b][a] = true;
		degree[a]++;
		degree[b]++;
	}
	int result = inf;
	for(int i = 1; i <= n; ++i)
		for(int j = i + 1; j <= n; ++j) {
			// we are O(n^2) times here
			if(t[i][j]) {
				// we are O(m) times here
				for(int k = j + 1; k <= n; ++k) {
					// O(m * n) times here
					if(t[i][k] && t[j][k])
						result = min(result, degree[i]+degree[j]+degree[k]);
				}
			}
		}
	if(result == inf) puts("-1");
	else printf("%d\n", result - 6);
	return 0;
}