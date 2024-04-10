#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9;
const int N = 1e6 + 13;
const int M = 1e9 + 7;

int sum(int a, int b) {
    int res = a + b;
    if(res >= M)
        res -= M;

    return res;
}

int p[N];

int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);

    p[0] = 1;
    for(int i = 1; i < N; i++) {
        p[i] = p[i - 1] * 2 % M;
    }

    int n, m, k;
    cin >> n >> m >> k;

    int cnt = 0;
    int ans = 1;
    vector<pii> e;
    for(int i = 0; i < m; i++) {
        int v, u;
        cin >> v >> u;

        v--;
        u--;

        int d = u - v;

        if(d != 1) {
            if(d == k + 1) {
                cnt++;
                e.emplace_back(v, u);
            } else {
                ans = 0;
            }
        }
    }

    if(ans == 0) {
        cout << 0;
        return 0;
    }

    if(e.empty()) {
        for(int i = 0; i < n - k - 1; i++) {
            ans = sum(ans, p[min(k, n - i - k - 2)]);
//            cout << i << ' ' << ans << ' '<< p[min(k, n - i - k - 2)] << endl;
        }

    } else {
        if(e[0].s > e.back().f) {
            ans = 0;
//            ans = p[k - e.size() + 1];
            for(int i = 0; i < e[0].f; i++) if(i + k + 1 > e.back().f){
                ans = sum(ans, p[min(k, n - i - k - 2) - e.size()]);
//                cout << i << ' ' << ans << endl;
            }
            ans = sum(ans, p[min(k, n - e[0].f - k - 2) - e.size() + 1]);
        } else
            ans = 0;
    }

    cout << ans << endl;
}