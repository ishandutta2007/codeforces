#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAXN = 1e5 + 7;
const int INF = 1e16 + 7;

int n, m;
int a[MAXN], b[MAXN];

bool check(int want) {
    for (int i = 0; i < n; ++i) {
        b[i] = a[i];
    }   
    int u = n - 1;
    while (b[u] == 0) {
        --u;
    }   
    for (int i = 0; i < m; ++i) {
        int t = want - u - 1;
        while (1) {
            if (t < 0) {
                break;
            }   
            else if (t >= b[u]) {
                t -= b[u];
                if (u == 0) {
                    return 1;
                }   
                --u;
            }   
            else {
                b[u] -= t;
                break;
            }   
        }   
    }   
    return 0;
}   

signed main() {
    #ifdef HOME
        freopen("input.txt", "r", stdin);
    #endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }   

    int l = -1;
    int r = INF;
    while (l < r - 1) {
        int mid = (l + r) >> 1;
        if (check(mid)) {
            r = mid;
        }   
        else {
            l = mid;
        }   
    }   

    cout << r << '\n';
    return 0;
}