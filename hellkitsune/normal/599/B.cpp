#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int a[100001], b[100001], cnt[100001] = {}, pos[100001];
int n, m;

int main() {
    scanf("%d%d", &n, &m);
    REP(i, n) {
        int x;
        scanf("%d", &x), --x;
        ++cnt[x];
        pos[x] = i;
    }
    bool amb = false;
    REP(i, m) {
        int x;
        scanf("%d", &x), --x;
        if (cnt[x] == 0) {
            printf("Impossible\n");
            return 0;
        } else if (cnt[x] > 1) {
            amb = true;
        } else {
            a[i] = pos[x] + 1;
        }
    }
    if (amb) {
        printf("Ambiguity\n");
    } else {
        printf("Possible\n");
        REP(i, m) printf("%d ", a[i]);
        printf("\n");
    }
    return 0;
}