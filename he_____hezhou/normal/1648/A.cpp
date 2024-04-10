#include <bits/stdc++.h>
using namespace std;
vector < int > pos[200010];
const int k = 100000;
int n, m;
long long calc(vector < int > &a) {
    sort(a.begin(), a.end());
    long long ans = 0;
    for (int i = 0; i < a.size(); i++) {
        ans += 1ll * i * a[i];
        ans -= 1ll * (a.size() - i - 1) * a[i];
    }
    return ans;
}
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int x;
            scanf("%d", &x);
            pos[x].push_back(i);
            pos[x + k].push_back(j);
        }
    }
    long long ans = 0;
    for (int i = 1; i <= 2 * k; i++) ans += calc(pos[i]);
    cout << ans << endl;
}