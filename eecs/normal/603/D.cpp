#include <bits/stdc++.h>
using namespace std;

const int maxn = 2010;
int n, ans;
double x[maxn], y[maxn];

int main() {
    scanf("%d", &n);
    for (int i = 1, a, b, c; i <= n; i++) {
        scanf("%d %d %d", &a, &b, &c);
        x[i] = 1.0 * a * c / (a * a + b * b);
        y[i] = 1.0 * b * c / (a * a + b * b);
    }
    for (int i = 1; i <= n; i++) {
        vector<double> V;
        int cnt = 0;
        for (int j = i + 1; j <= n; j++) {
            if (abs(x[i] - x[j]) > 1e-12) V.push_back((y[i] - y[j]) / (x[i] - x[j]));
            else if (abs(y[i] - y[j]) < 1e-12) cnt++;
            else V.push_back(1e18);
        }
        ans += cnt * (n - i - cnt);
        sort(V.begin(), V.end());
        for (int j = 0, k; j < V.size(); j = k) {
            for (k = j; k < V.size() && abs(V[j] - V[k]) < 1e-12; k++);
            ans += (k - j) * (k - j - 1) / 2;
        }
    }
    printf("%d\n", ans);
    return 0;
}