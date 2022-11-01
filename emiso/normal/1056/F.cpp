#include <bits/stdc++.h>

using namespace std;

double C, T, p9[110];
int z, a[110], p[110], n, on[1001][101];
double dp[1001][101];
vector<int> used[1001];

int main() {
    scanf("%d", &z);

    p9[0] = 1;
    for(int i = 1; i < 110; i++)
        p9[i] = p9[i-1] * 0.9;

    while(z--) {
        for(int i = 0; i < 1001; i++) {
            used[i].clear();
        }
        memset(on, 0, sizeof on);

        scanf("%d %lf %lf", &n, &C, &T);

        vector<pair<int, int>> prob;
        for(int i = 0; i < n; i++) {
            scanf("%d %d", &a[i], &p[i]);
            prob.emplace_back(a[i], p[i]);
        }
        sort(prob.begin(), prob.end(), greater<pair<int,int>>());
        for(int i = 0; i < n; i++) {
            a[i] = prob[i].first;
            p[i] = prob[i].second;
        }

        used[0].push_back(0);
        on[0][0] = 1;
        for(int i = 0; i < n; i++) {
            for(int score = 1000; score >= p[i]; score--) {
                for(int x : used[score - p[i]]) {
                    double st = dp[score-p[i]][x];

                    int nq = x + 1;
                    double nt = st + a[i] / p9[nq];

                    if(!on[score][nq] || nt < dp[score][nq]) {
                        if(!on[score][nq]) {
                            used[score].push_back(nq);
                            on[score][nq] = 1;
                        }
                        dp[score][nq] = nt;
                    }
                }
            }
        }

        int ans = 0;
        for(int score = 1000; ans == 0 && score > 0; score--) {
            for(int x : used[score]) {
                double tq = dp[score][x];
                double aq = C, bq = (1 - T*C + C*10*x), cq = (tq - T + 10 * x);
                double delta = bq*bq - 4*aq*cq;

                if(tq  + 10*x <= T + 1e-6) {
                    ans = score;
                    break;
                }

                if(delta >= 0) {
                    double t1 = (-bq + sqrt(delta)) / (2 * aq);
                    double t2 = (-bq - sqrt(delta)) / (2 * aq);

                    if(t1 >= 0 && t1 + 10*x + tq/(1 + C*t1) <= T + 1e-6) {
                        ans = score;
                        break;
                    }

                    if(t2 >= 0 && t2 + 10*x + tq/(1 + C*t2) <= T + 1e-6) {
                        ans = score;
                        break;
                    }
                }
            }
        }

        printf("%d\n", ans);
    }
    return 0;
}