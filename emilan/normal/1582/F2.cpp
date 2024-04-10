#include <bits/stdc++.h>

using namespace std;

const int A = 5001;
const int K = 8192;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;

    array<vector<int>, A> a_try;
    bitset<K> xum_vis;
    array<int, K> xum_lb;
    xum_lb.fill(A);
    auto update = [&](int a_val, int xum) {
        int new_xum = xum ^ a_val;
        for (int i = a_val + 1; i < xum_lb[new_xum]; i++) {
            a_try[i].push_back(new_xum);
        }
        xum_vis[new_xum] = true;
        xum_lb[new_xum] = min(xum_lb[new_xum], a_val + 1);
    };
    update(0, 0);

    for (int i = 0; i < n; i++) {
        for (int xum : a_try[ a[i] ]) update(a[i], xum);
        a_try[ a[i] ].clear(); // cuz new lbs are strictly greater
    }

    vector<int> ans;
    for (int i = 0; i < K; i++) {
        if (xum_vis[i]) ans.push_back(i);
    }

    int m = ans.size();
    cout << m << "\n";
    for (int i = 0; i < m; i++) {
        cout << ans[i] << " \n"[i == m - 1];
    }
}