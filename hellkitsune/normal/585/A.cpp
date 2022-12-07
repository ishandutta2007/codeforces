#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, ans = 0;
int v[5000], d[5000], p[5000];
vector<int> ret;
bool toProcess[5000] = {};

void decr(int pos, int val) {
    for (int i = pos; i < n; ++i) if (p[i] >= 0) {
        p[i] = max(-1, p[i] - val);
        if (p[i] < 0) {
            decr(i + 1, d[i]);
        }
    }
}

int main() {
    scanf("%d", &n);
    REP(i, n) scanf("%d%d%d", v + i, d + i, p + i);
    REP(i, n) if (p[i] >= 0) {
        ++ans;
        ret.pb(i + 1);
        for (int j = i + 1; j < n; ++j) if (p[j] >= 0) {
            p[j] = max(-1, p[j] - v[i]);
            v[i] = max(0, v[i] - 1);
            if (p[j] < 0) {
                toProcess[j] = true;
            }
        }
        for (int j = i + 1; j < n; ++j) if (toProcess[j]) {
            decr(j + 1, d[j]);
            toProcess[j] = false;
        }
    }
    printf("%d\n", ans);
    for (int x : ret) printf("%d ", x);
    printf("\n");
    return 0;
}