#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>

#define mp make_pair

using namespace std;

int w[1100];
int ord[1100];
int used[1100];
int stacking_order[1100];
int n, m, seen;

int main() {
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++) scanf("%d", &w[i]);
    for (int i = 0; i < m; i++) {
        scanf("%d", &ord[i]); ord[i]--;

        if (!used[ord[i]]) {
            used[ord[i]] = 1;
            stacking_order[seen++] = ord[i];
        }

    }

    int ans = 0;

    for (int i = 0; i < m; i++) {
        int j;
        for (j = 0; stacking_order[j] != ord[i]; j++);
        for (int k = j-1; k >= 0; k--) {
            ans += w[stacking_order[k]];
            stacking_order[k+1] = stacking_order[k];    
        }
        stacking_order[0] = ord[i];
    }

    printf("%d\n", ans);
}