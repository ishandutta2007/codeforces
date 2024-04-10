#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[200010];
void rmain() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) scanf("%d", a + i);
    sort(a + 1, a + 1 + m);
    a[m + 1] = a[1] + n;
    vector <int> v;
    for (int i = 1; i <= m; i++) v.push_back(a[i + 1] - a[i] - 1);
    sort(v.begin(), v.end(), greater <int> ());
    int ans = 0, need = 0;
    for (int i = 0; i < v.size(); i++) {
        v[i] -= 2 * need;
        if (v[i] <= 0) break;
        if (v[i] == 1 || v[i] == 2) ans++, need++;
        else need += 2, ans += v[i] - 1;
    }
    printf("%d\n", n - ans);
}
int main() {
    int T;
    scanf("%d", &T);
    while (T--) rmain();
}