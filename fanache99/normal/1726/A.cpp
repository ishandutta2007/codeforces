#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2000;
const int INF = 1e9;

int v[MAXN];

int main() {
    // ifstream cin("/home/stefanb/work/platform/src/app/shm_clean/input.txt");
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; test++) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        int ans = -INF;
        for (int i = 0; i < n; i++) {
            ans = max(ans, v[i] - v[(i + 1) % n]);
        }
        for (int i = 1; i < n - 1; i++) {
            ans = max(ans, max(v[i] - v[0], v[n - 1] - v[i]));
        }
        cout << ans << "\n";
    }
    return 0;
}