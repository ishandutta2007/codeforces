#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <int, int> pii;
typedef pair <pii, int> ppi;

vector <vector <int> > a;
vector <vector <int> > pmn, pmx, smn, smx;
vector <int> all;
int be[1000010];
char col[1000010];
int pr[1000010], su[1000010];
int mxp[1000010], mnp[1000010], mxs[1000010], mns[1000010];

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		int n, m; scanf("%d%d", &n, &m);
		a.clear(), a.resize(n);
		pmn = vector <vector <int> >(n, vector <int>(m)), pmx = vector <vector <int> >(n, vector <int>(m));
		smn = vector <vector <int> >(n, vector <int>(m)), smx = vector <vector <int> >(n, vector <int>(m));
		for (int i = 0; i < n; i++) {
			a[i].resize(m);
			for (int j = 0; j < m; j++) {
				scanf("%d", &a[i][j]);
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				pmx[i][j] = pmn[i][j] = smx[i][j] = smn[i][j] = a[i][j];
			}
			for (int j = 1; j < m; j++) {
				pmn[i][j] = min(pmn[i][j], pmn[i][j - 1]);
				pmx[i][j] = max(pmx[i][j], pmx[i][j - 1]);
			}
			for (int j = m - 2; j >= 0; j--) {
				smx[i][j] = max(smx[i][j], smx[i][j + 1]);
				smn[i][j] = min(smn[i][j], smn[i][j + 1]);
			}
		}
		for (int j = 0; j + 1 < m; j++) {
			all.clear();
			for (int i = 0; i < n; i++) {
				all.push_back(i);
			}
			sort(all.begin(), all.end(), [](const int &x, const int &y) {return pmx[x] < pmx[y];});
			for (int i = 0; i < all.size(); i++) {
				mxp[i] = pmx[all[i]][j], mnp[i] = smn[all[i]][j + 1], mxs[i] = smx[all[i]][j + 1], mns[i] = pmn[all[i]][j];
			}
			for (int i = 1; i < all.size(); i++) {
				mxp[i] = max(mxp[i], mxp[i - 1]), mnp[i] = min(mnp[i - 1], mnp[i]);
			}
			for (int i = n - 2; i >= 0; i--) {
				mxs[i] = max(mxs[i], mxs[i + 1]), mns[i] = min(mns[i + 1], mns[i]);
			}
			for (int i = 0; i + 1 < all.size(); i++) {
				if (mxp[i] < mns[i + 1] && mnp[i] > mxs[i + 1]) {
					printf("YES\n");
					for (int t = 0; t <= i; t++) {
						col[all[t]] = 'B';
					}
					for (int t = i + 1; t < all.size(); t++) {
						col[all[t]] = 'R';
					}
					col[n] = '\0';
					printf("%s %d\n", col, j + 1);
					goto QWQ;
				}
			}
		}
		printf("NO\n");
		continue;
		QWQ:;
	}
	return 0;
}