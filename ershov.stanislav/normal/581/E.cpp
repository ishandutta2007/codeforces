#include <bits/stdc++.h>

#define pb push_back

#define all(s) (s).begin(), (s).end()
#define sz(s) ((int) ((s).size()))

using namespace std;

const int N = 2e5 + 100;

int e, s, n, m;
int t[N], x[N];
vector<int> v[4];
vector<int> len[4];

int get(int t, int x) {
    int i = (int) (lower_bound(all(v[t]), x) - v[t].begin());
    return len[t][i] + max(v[t][i] - x - s, 0);
}

int main()
{
    scanf("%d%d%d%d", &e, &s, &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", t + i, x + i);
        if (x[i] >= e) {
            continue;
        }
        for (int j = 1; j <= t[i]; j++) {
            v[j].pb(x[i]);
        }
    }
    for (int t = 1; t <= 3; t++) {
        v[t].pb(e);
        sort(all(v[t]));
        v[t].resize(distance(v[t].begin(), unique(all(v[t]))));
        len[t].resize(sz(v[t]));
        for (int i = sz(v[t]) - 2; i >= 0; i--) {
            len[t][i] = len[t][i + 1] + max(0, v[t][i + 1] - v[t][i] - s);
        }
    }
    for (int i = 0; i < m; i++) {
        int f;
        scanf("%d", &f);
        int a1 = get(1, f);
        int a2 = get(2, f);
        int a3 = get(3, f);
        if (a1 > 0) {
            printf("-1 -1\n");
        } else {
            printf("%d %d\n", a2, a3 - a2);
        }
    }
    return 0;
}