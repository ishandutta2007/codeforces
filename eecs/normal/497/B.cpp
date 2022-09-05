#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int n, a[maxn], fir1[maxn], fir2[maxn], cur1[maxn], cur2[maxn];
vector<pair<int, int>> ans;

int main() {
    scanf("%d", &n);
    int c1 = 0, c2 = 0;
    memset(fir1, 0x3f, sizeof(fir1));
    memset(fir2, 0x3f, sizeof(fir2));
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        if (a[i] == 1) fir1[++c1] = i;
        else fir2[++c2] = i;
        cur1[i] = c1, cur2[i] = c2;
    }
    for (int i = 1; i <= n; i++) {
        c1 = c2 = 0;
        int w1 = 0, w2 = 0, lst = -1;
        while (1) {
            int pos = min(fir1[c1 + i], fir2[c2 + i]);
            if (pos > n) {
                if (c1 != cur1[n] || c2 != cur2[n]) lst = -1;
                break;
            }
            if (pos == fir1[c1 + i]) w1++, lst = 1;
            else w2++, lst = 2;
            c1 = cur1[pos], c2 = cur2[pos];
        }
        if (lst == 1 && w1 > w2 || lst == 2 && w2 > w1) {
            ans.emplace_back(max(w1, w2), i);
        }
    }
    sort(ans.begin(), ans.end());
    printf("%d\n", ans.size());
    for (auto p : ans) {
        printf("%d %d\n", p.first, p.second);
    }
    return 0;
}