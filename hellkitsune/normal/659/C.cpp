#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, m;
bool used[500000] = {};
vector<int> ans;

int main() {
    scanf("%d%d", &n, &m);
    REP(i, n) {
        int x;
        scanf("%d", &x);
        if (x < 500000) used[x] = true;
    }
    for (int i = 1; i <= m; ++i) if (!used[i]) {
        ans.pb(i);
        m -= i;
    }
    printf("%d\n", (int)ans.size());
    for (int x : ans) printf("%d ", x);
    printf("\n");
    return 0;
}