#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, x1, x2;
int k[100000], b[100000];
LL y[100000], yy[100000];
int ord1[100000], ord2[100000];

inline bool cmp1(const int &lhs, const int &rhs) {
    if (y[lhs] != y[rhs]) return y[lhs] < y[rhs];
    return k[lhs] < k[rhs];
}

inline bool cmp2(const int &lhs, const int &rhs) {
    if (yy[lhs] != yy[rhs]) return yy[lhs] < yy[rhs];
    return k[lhs] > k[rhs];
}

int main() {
    scanf("%d", &n);
    scanf("%d%d", &x1, &x2);
    REP(i, n) scanf("%d%d", k + i, b + i);
    REP(i, n) y[i] = (LL)k[i] * x1 + b[i];
    REP(i, n) yy[i] = (LL)k[i] * x2 + b[i];
    REP(i, n) ord1[i] = ord2[i] = i;
    sort(ord1, ord1 + n, cmp1);
    sort(ord2, ord2 + n, cmp2);
    REP(i, n) if (ord1[i] != ord2[i]) {
        printf("YES\n");
        return 0;
    }
    printf("NO\n");
    return 0;
}