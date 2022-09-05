#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 150010;
int n, ord[maxn], ord2[maxn];
ll T, p[maxn], t[maxn];
double a[maxn];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &p[i]);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &t[i]), T += t[i];
    }
    iota(ord + 1, ord + n + 1, 1);
    sort(ord + 1, ord + n + 1, [&](int i, int j) {
        return 1LL * p[j] * t[i] < 1LL * p[i] * t[j];
    });
    auto chk = [&](double c) {
        vector<pair<ll, double>> V;
        double x = 0;
        for (int i = 1, j; i <= n; i = j) {
            for (j = i; j <= n && 1LL * p[ord[i]] * t[ord[j]] == 1LL * p[ord[j]] * t[ord[i]]; j++);
            ll all = 0;
            for (int k = i; k < j; k++) {
                all += t[ord[k]];
            }
            for (int k = i; k < j; k++) {
                V.emplace_back(p[ord[k]], p[ord[k]] * (1 - c * (x + t[ord[k]]) / T));
                V.emplace_back(p[ord[k]], p[ord[k]] * (1 - c * (x + all) / T));
            }
            x += all;
        }
        sort(V.begin(), V.end());
        for (int i = 1; i < n << 1; i++) {
            if (V[i].second < V[i - 1].second) return 0;
        }
        return 1;
    };
    double l = 0, r = 1;
    while (r - l > 1e-9) {
        double mid = (l + r) / 2;
        chk(mid) ? l = mid : r = mid;
    }
    printf("%.10f\n", l);
    return 0;
}