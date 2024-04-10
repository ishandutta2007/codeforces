#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 7;

int n;
int a[MAXN];
int ans[MAXN];
int cnt[MAXN];

bool used[MAXN];

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    
    set <int> ms;
    for (int i = 1; i <= n; ++i) {
        ms.insert(i);
    }

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        ++cnt[a[i]];
        ms.erase(a[i]);
    }   
    
    int q = 0;
    for (int i = 0; i < n; ++i) {
        if (cnt[a[i]] > 1 && (*ms.begin() < a[i] || used[a[i]])) {
            ans[i] = *ms.begin();
            ms.erase(ms.begin());
            --cnt[a[i]];
            ++q;
        }
        else {
            ans[i] = a[i];
            used[a[i]] = 1;
        }   
    }   
    
    cout << q << '\n';
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << ' ';
    }
    cout << '\n';

    return 0;
}