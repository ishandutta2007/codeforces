#include <bits/stdc++.h>

using namespace std;

int n, l, k;
double dp[203][203][203], ret;

struct tour {
    double p;
    int a;

    bool operator <(const tour &o) const {
        return a > o.a;
    }
} t[203];

double solve(int pos, int space, int wins) {
    if(space < 0) return 0;
    wins = max(0, wins);
    if(pos == n) {
        if(wins == 0) return 1;
        else return 0;
    }
    space = min(space, 201);


    double &x = dp[pos][space][wins];
    if(x != -1) return x;

    x = t[pos].p * solve(pos + 1, space + t[pos].a, wins - 1);
    x += (1 - t[pos].p) * solve(pos + 1, space, wins);

    return x;
}

int main() {
    scanf("%d %d %d", &n, &l, &k);
    for(int i=0; i<n; i++) {
        scanf("%lf", &t[i].p);
        t[i].p /= 100;
    }

    for(int i=0; i<n; i++) {
        scanf("%d", &t[i].a);
    }

    sort(t, t + n);

    for(int i=0; i<202; i++)
        for(int j=0; j<202; j++)
            for(int K=0; K<202; K++)
                dp[i][j][K] = -1;

    printf("%.9f\n", solve(0, k, l));
    return 0;
}