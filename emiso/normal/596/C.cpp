#include <bits/stdc++.h>

using namespace std;

int n, x[100010], y[100010], w[100010], ans[100010], in[100010];
map<pair<int, int>, int> id;
map<int, vector<int>> ok;

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d %d", &x[i], &y[i]);
        id[{x[i], y[i]}] = i;
    }
    for(int i = 1; i <= n; i++) {
        scanf("%d", &w[i]);
    }
    for(int i = 0; i < n; i++) {
        if(!id.count({x[i], y[i]+1}) && !id.count({x[i]+1, y[i]})) {
            ok[y[i]-x[i]].push_back(i);
        }
    }

    for(int i = n; i > 0; i--) {
        vector<int> &v = ok[w[i]];

        if(v.empty()) {
            puts("NO");
            return 0;
        }

        int p = v.back();
        ans[i] = p;
        v.pop_back();

        if(y[p]) {
          int q = id[{x[p], y[p]-1}];
          if(!in[q]) ok[y[q]-x[q]].push_back(q);
          in[q] = 1;
        }
        if(x[p]) {
          int q = id[{x[p]-1, y[p]}];
          if(!in[q]) ok[y[q]-x[q]].push_back(q);
          in[q] = 1;
        }
    }

    puts("YES");
    for(int i = 1; i <= n; i++)
        printf("%d %d\n", x[ans[i]], y[ans[i]]);

    return 0;
}