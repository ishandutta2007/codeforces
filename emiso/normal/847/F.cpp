#include <bits/stdc++.h>

using namespace std;

int n, k, m, a, votes[110], ans[110];

struct cand {
    int q, l, ind;
} cands[110];

bool cmp(cand a, cand b) {
    if (a.q == b.q)
        return a.l < b.l;
    return a.q > b.q;
}

int main() {
    scanf("%d %d %d %d", &n, &k, &m, &a);
    for (int i = 0; i < a; i++) {
        scanf("%d", &votes[i]);
        cands[votes[i]].q++;
        cands[votes[i]].l = i+1;
    }

    for (int i = 1; i <= n; i++)
        cands[i].ind = i;

    sort(cands+1, cands+n+1, cmp);

    for (int i = 1; i <= n; i++) {
        if (n == k && cands[i].q == 0) {
            if (m - a == 0) ans[cands[i].ind] = 3;
            else ans[cands[i].ind] = 2;
        }
        else if (n == k) ans[cands[i].ind] = 1;
        else {
            int lft = m - a, passed = 0;
            for (int j = 1; j <= n; j++)
                if (j != i) {
                    if (cands[j].q > cands[i].q) passed++;
                    else if (cands[j].q == cands[i].q && cands[j].l < cands[i].l) passed++;
                    else {
                        if (cands[i].q - cands[j].q + 1 > lft) break;
                        else { passed++; lft -= cands[i].q - cands[j].q + 1; }
                    }

                    if (passed == k) break;
                }

            if (passed < k) {
                if (cands[i].q == 0 && m - a == 0) ans[cands[i].ind] = 3;
                else if (cands[i].q == 0) ans[cands[i].ind] = 2;
                else ans[cands[i].ind] = 1;
            }
            else {
                int lft = k, pos = 1;
                while (1) {
                    if (pos != i) lft--;
                    if (lft == 0) break;
                    pos++;
                }

                if (cands[i].q + m - a == 0) ans[cands[i].ind] = 3;
                else {
                    if (cands[i].q + m - a > cands[pos].q) ans[cands[i].ind] = 2;
                    else if (cands[i].q == cands[pos].q && cands[i].l < cands[pos].l) ans[cands[i].ind] = 2;
                    else ans[cands[i].ind] = 3;
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (i > 1) printf(" ");
        printf("%d", ans[i]);
    }
    printf("\n");

    return 0;
}