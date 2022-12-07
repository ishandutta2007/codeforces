#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, m;
int cnt[1000001];
vector<int> pos[1000001];
vector<int> di[1000001];
vector<int> vans;

int main() {
    scanf("%d%d", &n, &m);
    REP(i, n) {
        int x;
        scanf("%d", &x);
        if (x > m) continue;
        ++cnt[x];
        pos[x].pb(i + 1);
    }
    for (int i = 1; i <= m; ++i) {
        for (int j = i; j <= m; j += i) {
            di[j].pb(i);
        }
    }
    int ans = -1, bestInd = -1;
    for (int i = 1; i <= m; ++i) {
        int cur = 0;
        for (int x : di[i]) {
            cur += cnt[x];
        }
        if (ans < cur) {
            ans = cur;
            bestInd = i;
        }
    }
    for (int x : di[bestInd]) {
        for (int y : pos[x]) {
            vans.pb(y);
        }
    }
    sort(vans.begin(), vans.end());
    printf("%d %d\n", bestInd, ans);
    for (int x : vans) printf("%d ", x);
    printf("\n");
    return 0;
}