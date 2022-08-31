#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-9;
double p[1010][1010];
int n, vis[1010];
double prod[1010], ans[1010];
int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++) scanf("%lf", p[i] + j), p[i][j] /= 100;
    for(int i = 1; i < n; i++) prod[i] = 1, ans[i] = 1;
    while(1) {
        int _min = -1;
        for(int i = 1; i <= n; i++) {
            if(vis[i] || prod[i] > 1 - eps) continue;
            if(_min == -1 || ans[_min] / (1 - prod[_min]) > ans[i] / (1 - prod[i])) _min = i;
        }
        vis[_min] = 1;
        ans[_min] /= 1 - prod[_min];
        // cerr << _min << ' ' << ans[_min] << ' ' << prod[_min] << endl;
        if(_min == 1) break;
        for(int i = 1; i <= n; i++) {
            if(!vis[i]) {
                ans[i] += prod[i] * p[i][_min] * ans[_min];
                prod[i] *= (1 - p[i][_min]);
            }
        }
    }
    return printf("%.10lf\n", ans[1]), 0;
}