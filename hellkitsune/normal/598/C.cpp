#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;
typedef long double Double;

const Double PI = atan2((Double)0, (Double)-1);
int n, x, y;
Double ang[100000];

int ord[100000];

inline bool cmp(const int &lhs, const int &rhs) {
    return ang[lhs] < ang[rhs];
}

Double getAng(Double a, Double b) {
    Double ret = b - a;
    if (ret > PI) ret = 2 * PI - ret;
    return ret;
}

int main() {
    //freopen("input.txt", "r", stdin);
    scanf("%d", &n);
    REP(i, n) {
        scanf("%d%d", &x, &y);
        ang[i] = atan2((Double)y, (Double)x);
    }
    REP(i, n) ord[i] = i;
    sort(ord, ord + n, cmp);
    Double best = getAng(ang[ord[0]], ang[ord[1]]);
    int bestInd = 0;
    for (int i = 1; i < n - 1; ++i) {
        Double cur = getAng(ang[ord[i]], ang[ord[i + 1]]);
        if (cur < best) {
            best = cur;
            bestInd = i;
        }
    }
    Double cur = getAng(ang[ord[n - 1]], ang[ord[0]] + 2 * PI);
    if (cur < best) {
        best = cur;
        bestInd = n - 1;
    }
    printf("%d %d\n", ord[bestInd] + 1, ord[(bestInd + 1) % n] + 1);
    return 0;
}