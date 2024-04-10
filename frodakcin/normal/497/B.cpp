#include <iostream>
#include <cstdio>

#include <utility>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;
#define mp make_pair

const int MAXN = 1e5 + 100;
const int INF = 1e9 + 1e6;

int N;
int a[MAXN], p[3], s[3][MAXN], l[3][MAXN];
pii ans[MAXN];

bool gr(int n) {
    for(int i = 1;i <= 2;i++) if(i != n and p[i] >= p[n]) return false;
    return true;
}

int main() {
    scanf("%d", &N);
    for(int i = 1;i <= N;i++) scanf("%d", a + i);
    for(int i = 1;i <= 2;i++) p[i] = s[i][0] = 0;
    for(int i = 1;i <= N;s[a[i]][i]++, i++) for(int j = 1;j <= 2;j++) s[j][i] = s[j][i - 1];
    for(int i = 1, j;i <= 2;i++) for(j = 1, l[i][0] = 0;j <= N;j++) if(s[i][j] != s[i][j - 1]) l[i][s[i][j]] = j;
    int ansc = 0;
    for(int t = 1;t <= N;t++) {
        for(int i = 1;i <= 2;i++) p[i] = 0;
        int v = -1;
        for(int e = 0, f, pn, j, m;v == -1 and e < N;e = f) {
            for(f = INF, j = 1;j <= 2;j++) if(s[j][N] >= t + s[j][e] and (m = l[j][s[j][e] + t]) < f) pn = j, f = m;
            if(f == INF) break;
            p[pn]++;
            if(f == N and gr(pn)) v = p[pn];
        }
        if(v != -1) ans[ansc++] = mp(v, t);
    }
    sort(ans, ans + ansc);
    printf("%d\n", ansc);
    for(int i = 0;i < ansc;i++) printf("%d %d\n", ans[i].first, ans[i].second);
    return 0;
}