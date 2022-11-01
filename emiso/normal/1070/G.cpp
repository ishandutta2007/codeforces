#include <bits/stdc++.h>

using namespace std;

int n, m, s[110], h[110], a[110];
bool used[110], gone[110];

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &s[i], &h[i]);
		s[i]--;
	}
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
		
	for (int i = 0; i < n; i++) {
		memset(used, 0, sizeof used);
		memset(gone, 0, sizeof gone);
		vector < int > ans;
		
		for (int j = 0; j < m; j++) {
			int best = -1, ind, d = 1000;
			for (int k = 0; k < m; k++) {
				if (gone[k]) continue;
				
				if (s[k] > i) {
					int hp = h[k], pos = s[k];
					while (pos != i) {
						pos--;
						if (!used[pos]) hp += a[pos];
						if (hp < 0) break;
					}
					if (hp >= 0 && s[k]-i < d) {
						d = s[k]-i;
						best = s[k];
						ind = k;
					}
				}
				else {
					int hp = h[k], pos = s[k];
					while (pos != i) {
						pos++;
						if (!used[pos]) hp += a[pos];
						if (hp < 0) break;
					}
					if (hp >= 0 && i-s[k] < d) {
						d = i-s[k];
						best = s[k];
						ind = k;
					}
				}
			}
			
			if (best == -1) break;
			
			ans.push_back(ind+1);
			gone[ind] = true;
			while (best != i) {
				if (best > i) best--;
				else best++;
				used[best] = true;
			}
		}
		
		if (ans.size() == m) {
			printf("%d\n", i+1);
			for (int j = 0; j < m; j++) {
				if (j) printf(" ");
				printf("%d", ans[j]);
			}
			printf("\n");
			return 0;
		}
	}
	printf("-1\n");
	return 0;
}