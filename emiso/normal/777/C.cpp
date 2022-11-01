#include <bits/stdc++.h>

#define MN 1000100
#define w1 while(1)

using namespace std;
typedef long long ll;

int n, m, x, k, l, r;
vector<int> b;

int main() {
    scanf("%d %d", &n, &m);

    vector<vector<int> > a(n + 4, vector<int>(m + 4, 0));

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            scanf("%d", &x);
            a[i][j] = x;
        }
    }

    map<pair<int, int>, int> ans;
    vector<vector<int> > decs(n + 4, vector<int>(m + 4, 0));

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            decs[i][j] = (decs[i-1][j] + ((a[i][j] < a[i-1][j]) ? 1 : 0));
        }
    }

    scanf("%d", &k);
    for(int i = 1; i <= k; i++) {
        scanf("%d %d", &l, &r);

        pair<int, int> p = make_pair(l, r);
        if(ans.find(p) != ans.end()) {
            printf("%s\n", (ans[p]) ? "Yes" : "No");
            continue;
        }

        int flag = 0;
        for(int z = 1; z <= m; z++) {
            bool isp = (decs[r][z] - decs[l][z] == 0);
            //printf("%d %d %d\n", z, decs[r][z], decs[l][z]);
            flag |= isp;
        }

        ans[p] = (flag);

        printf("%s\n", flag ? "Yes" : "No");
    }
    return 0;
}