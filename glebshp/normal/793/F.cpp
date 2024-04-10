#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second

const int size = 100 * 1000 + 100;
const int bsize = 400;

int n, m, q;
int fin[size];
int l[size], r[size];
vector <int> vertex[size];
vector <int> qs[size];
int st[size];
int qx[size], qy[size];
int ans[size];
int lene;

int go_small(int lb, int rb) {
	int cur = lb;
	for (int i = lb; i <= rb; i++)
		if (fin[i] >= lb && fin[i] <= cur) {
			cur = i;
		}

	return cur;
}

int main () {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
    	fin[i] = -1;
    for (int i = 0; i < m; i++) {
    	scanf("%d%d", &l[i], &r[i]);
    	l[i]--, r[i]--;

    	vertex[l[i]].pb(r[i]);
    	fin[r[i]] = l[i];
    }

    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
    	scanf("%d%d", &qx[i], &qy[i]);
    	qx[i]--, qy[i]--;
    	qs[qx[i]].pb(i);

    	if (qx[i] / bsize == qy[i] / bsize) {
    		ans[i] = go_small(qx[i], qy[i]);
    	}
    }

	for (int j = bsize; j < n; j += bsize) {
		lene = 0;
		for (int i = j - 1; i >= 0; i--) {
			st[lene++] = i;
			for (auto& e : vertex[i]) {
				if (e <= j) {
					while (lene > 0 && st[lene - 1] < e)
						lene--; 
				}
			}
			for (auto& mq : qs[i]) {
				if (qy[mq] >= j && qy[mq] < j + bsize) {
					int cur;
					if (lene == 0) {
						cur = j;			
					} else {
						cur = st[lene - 1];
					}

					for (int k = j; k <= qy[mq]; k++) {
						if (fin[k] >= i && fin[k] <= cur)
							cur = k;
					}

					ans[mq] = cur;
				}
			}
		}
	}

    for (int i = 0; i < q; i++)
    	printf("%d\n", ans[i] + 1);

    return 0;
}