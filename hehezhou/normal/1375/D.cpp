#include <bits/stdc++.h>
using namespace std;
int a[1010], n, buc[1010];
vector < int > ans;
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) scanf("%d", a + i);
        ans.clear();
        while (1) {
            for (int i = 0; i <= n; i++) buc[i] = 0;
            for (int i = 1; i <= n; i++) if (a[i] < n) buc[a[i]] = 1;
            int mex = 0;
            while (buc[mex]) mex++;
            if (mex == 0) {
                int tag = 0;
                for (int i = 1; i <= n; i++) if (a[i] != i) {
                    tag = 1;
                    ans.push_back(i);
                    a[i] = 0;
                    break;
                }
                if (tag == 0) break;
            }
            else {
                ans.push_back(mex);
                a[mex] = mex;
            }
        }
        printf("%d\n", ans.size());
        for (int i = 0; i < ans.size(); i++) printf("%d%c", ans[i], " \n"[i == ans.size() - 1]);
    }
}